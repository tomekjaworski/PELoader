#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string>
#include <assert.h>
#include <cstring>
#include <sys/mman.h>
#include <sys/resource.h>
#include <vector>
#include <list>
#include <system_error>

#include "Host/AnsiCodes.h"
#include "FileDataProvider.hpp"
#include "WinAPI/BasicTypes.hpp"
#include "WinAPI/InternalHelpers.hpp"
#include "Helpers/Helper.hpp"
#include "WinApiFunction.h"
#include "Globals.hpp"
#include "Host/Constants.hpp"
#include "Stub/Stub.hpp"

#include "Loader/LoaderError.hpp"
#include "Loader/Loader.hpp"
#include "WinAPI/Kernel32.hpp"

namespace Globals = Core::Globals;
namespace Structures = Core::Loader::Structures;
namespace Enums = Core::Loader::Enums;

std::list<WinApiFunction> winapi;

void ResizeStack(void) {
    const rlim_t new_stack_size = 32 * 1024 * 1024;
    struct rlimit lim;

    int res = getrlimit(RLIMIT_STACK, &lim);
    if (res != 0)
        return;

    if (lim.rlim_cur >= new_stack_size)
        return;

    lim.rlim_cur = new_stack_size;
    res = setrlimit(RLIMIT_STACK, &lim);
    if (res != 0) {
        fprintf(stderr, "setrlimit=%d; errno=\n", res, errno);
        throw LoaderError("Unable to set stack's limit");
    }
}


int main() {
    Core::WinAPI::Kernel32_RegisterLibrary(winapi);

    printf("Simple WinApi Emulator; (C) 2021 Tomasz Jaworski\n");
    printf("Build for %d bits; Compiled on %s %s\n", __WORDSIZE, __DATE__, __TIME__);
    printf("Number of available emulations: %zu\n", winapi.size());
    printf("PID=%d\n", getpid());

    ResizeStack();

    int host_page_size = getpagesize();
    if (host_page_size != Core::Constants::CPUMemoryPageSize) {
        printf("The size of host's VM page differs expectations; should be %d but encountered %d.",
               Core::Constants::CPUMemoryPageSize, host_page_size);
        exit(2);
    } else
        printf("VM page size: %d\n", getpagesize());

    printf("\n");
    fflush(stdout);
    fflush(stderr);

    // -- start

#if defined(CPU32)
    std::string arguments = "aaa bbb ccc";
    std::string image_file = "/media/sf_CProgramming/SampleConsoleApplications/Release_Win32/simple_output.exe";
#elif defined(CPU64)
    std::string arguments = "aaa bbb ccc";
    std::string image_file = "/media/sf_CProgramming/SampleConsoleApplications/Release_x64/simple_output.exe";
    //std::string image_file =  "/media/sf_CProgramming/SampleConsoleApplications/Release_x64/simple_42.exe";
    //std::string image_file =  "/media/sf_CProgramming/SampleConsoleApplications/Release_x64/simple_io.exe";
    //std::string image_file = "/media/sf_CProgramming/SampleConsoleApplications/Release_x64/simple_file.exe";
#endif


    std::vector<Core::Loader::PageBlockEntry> allocated_pages;
    void* stack_bottom, * stack_top;
    Core::IMAGE_ENTRY_POINT entry_point;

    try {
        Globals::process_control_block.SetImageFileName(image_file);
        Globals::process_control_block.SetCommandLineArguments(arguments);

        FileDataProvider fdp(Globals::process_control_block.GetAnsiImageFileName());
        Core::Loader::Parsers::DosStubHeaderParser dos_parser(fdp.GetMemoryView());

        if (!dos_parser.IsValid())
            throw LoaderError("DOS executable header is not valid");

        const Structures::PE_EXECUTABLE_HEADER* pe_header = reinterpret_cast<const Structures::PE_EXECUTABLE_HEADER*>(
            fdp.GetMemoryView().GetData(0) + dos_parser.GetNewExecutableOffset()
        );

        if (pe_header->Magic != Core::Loader::Structures::PEExecutableHeaderMagic)
            throw LoaderError("Windows PE executable format is not valid");

        if (pe_header->Machine != Enums::MachineType::I386 && pe_header->Machine != Enums::MachineType::AMD64)
            throw LoaderError("Unsupported target architecture");

        if (!IsFlagSet<Enums::ImageCharacteristicFlags::EXECUTABLE_IMAGE>(pe_header->Characteristics))
            throw LoaderError("Unsupported image type (should be EXECUTABLE)");

        if (!IsFlagSet<Enums::ImageCharacteristicFlags::LARGE_ADDRESS_AWARE>(pe_header->Characteristics) &&
            !IsFlagSet<Enums::ImageCharacteristicFlags::_32BIT_MACHINE>(pe_header->Characteristics))
            throw LoaderError("Invalid image characteristics");

        if (pe_header->Machine == Enums::MachineType::I386 &&
            IsFlagSet<Enums::ImageCharacteristicFlags::LARGE_ADDRESS_AWARE>(pe_header->Characteristics))
            throw LoaderError("Invalid image characteristics");

        if (pe_header->Machine == Enums::MachineType::AMD64 &&
            IsFlagSet<Enums::ImageCharacteristicFlags::_32BIT_MACHINE>(pe_header->Characteristics))
            throw LoaderError("Invalid image characteristics");

        printf("Number of sections: %d\n", pe_header->NumberOfSections);

#if defined(CPU32)
        const Structures::PE32_OPTIONAL_HEADER* pe_optional_header = reinterpret_cast<const Structures::PE32_OPTIONAL_HEADER*>(
            fdp.GetMemoryView().GetData(0) + dos_parser.GetNewExecutableOffset() +
            sizeof(Structures::PE_EXECUTABLE_HEADER)
        );
#elif defined(CPU64)
        const Structures::PE64_OPTIONAL_HEADER* pe_optional_header = reinterpret_cast<const Structures::PE64_OPTIONAL_HEADER*>(
            fdp.GetMemoryView().GetData(0) + dos_parser.GetNewExecutableOffset() +
            sizeof(Structures::PE_EXECUTABLE_HEADER)
        );
#endif

        if (pe_optional_header->Windows.SectionAlignment != Core::Constants::CPUMemoryPageSize)
            throw LoaderError("Invalid section alignment; should be same as the host's memory page size");
        if (pe_optional_header->Windows.FileAlignment < 512 || pe_optional_header->Windows.FileAlignment > 65536)
            throw LoaderError("Invalid file alignment");
        if (!is_power_of_two(pe_optional_header->Windows.FileAlignment))
            throw LoaderError("Invalid file alignment");

        if (
            !(
                pe_optional_header->Standard.Magic == Enums::PEOptionalHeaderMagic::NT_HDR64
                && IsFlagSet<Enums::ImageCharacteristicFlags::LARGE_ADDRESS_AWARE>(pe_header->Characteristics)
            )
            &&
            !(
                pe_optional_header->Standard.Magic == Enums::PEOptionalHeaderMagic::NT_HDR32
                && IsFlagSet<Enums::ImageCharacteristicFlags::_32BIT_MACHINE>(pe_header->Characteristics)
            )
            )
            throw LoaderError("Invalid PE optional header");

#if defined(CPU64)
        const Structures::PE_SECTION_HEADER* pe_section_header = reinterpret_cast<const Structures::PE_SECTION_HEADER*>(
            fdp.GetMemoryView().GetData(0) + dos_parser.GetNewExecutableOffset() +
            sizeof(Structures::PE_EXECUTABLE_HEADER) +
            sizeof(Structures::PE64_OPTIONAL_HEADER)
        );
#elif defined(CPU32)
        const Structures::PE_SECTION_HEADER* pe_section_header = reinterpret_cast<const Structures::PE_SECTION_HEADER*>(
            fdp.GetMemoryView().GetData(0) + dos_parser.GetNewExecutableOffset() +
            sizeof(Structures::PE_EXECUTABLE_HEADER) +
            sizeof(Structures::PE32_OPTIONAL_HEADER)
        );
#endif

        for (int i = 0; i < pe_header->NumberOfSections; i++) {
            printf("Loading section %s...\n", pe_section_header[i].Name);

            uint32_t pages = pe_section_header[i].Misc.VirtualSize / pe_optional_header->Windows.SectionAlignment;
            if (pe_section_header[i].Misc.VirtualSize % pe_optional_header->Windows.SectionAlignment > 0)
                pages++;
            if (pages == 0)
                continue;

            void* dest = reinterpret_cast<void*>(pe_optional_header->Windows.ImageBase +
                                                 pe_section_header[i].VirtualAddress);
            void* pdest = mmap(dest, pages * Core::Constants::CPUMemoryPageSize, PROT_READ | PROT_WRITE | PROT_EXEC,
                               MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
            if (pdest != dest)
                throw LoaderError("Unable to map guest process memory into host memory");

            allocated_pages.emplace_back(pdest, pages);
            const void* psource = fdp.GetMemoryView().GetData(0) + pe_section_header[i].PointerToRawData;

            if (IsFlagSet<Enums::SectionFlags::CNT_INITIALIZED_DATA>(pe_section_header[i].Characteristics))
                std::memset(pdest, 0x00, pe_section_header[i].Misc.VirtualSize);
            else
                std::memset(pdest, 0xcc, pe_section_header[i].Misc.VirtualSize); // 0xcc -- kontrolowane śmieci

            uint32_t bytes_to_copy = std::min(pe_section_header[i].SizeOfRawData,
                                              pe_section_header[i].Misc.VirtualSize);
            std::memmove(pdest, psource, bytes_to_copy);

            printf("  VirtualAddress: %p, Pages: %d, SizeOfRawData: %u; Bytes copied: %u\n", pdest, pages,
                   pe_section_header[i].SizeOfRawData, bytes_to_copy);
            printf("  Flags: %08x\n", static_cast<uint32_t>(pe_section_header[i].Characteristics));
        }



        //
        // TIB - Thread Information Block
        //
        size_t tib_page_count = 1;
        using TIB = Core::Loader::Structures::THREAD_INFORMATION_BLOCK;
        TIB* ptib = reinterpret_cast<TIB*>(mmap(0x00000000, tib_page_count * Core::Constants::CPUMemoryPageSize,
                                                PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1,
                                                0));
        if (errno != 0)
            throw LoaderError("Unable to map guest process memory into host memory");
        allocated_pages.emplace_back(ptib, tib_page_count);

        // Tabela TIB zawiera głównie wskaźniki początkowe i limit; większość wskaźników przesuwana
        // jest wprzód. Zatem FF zwiększa szansę awarii w przypadku wykorzystania. Oby.
        memset(ptib, 0xFF, Core::Constants::CPUMemoryPageSize);


        // importy
        Structures::IMAGE_DATA_DIRECTORY_ENTRY import_data = pe_optional_header->DataDirectory[Enums::ImageDataDirectoryIndex::IMPORT];
        Structures::IMAGE_DATA_DIRECTORY_ENTRY import_address_table = pe_optional_header->DataDirectory[Enums::ImageDataDirectoryIndex::IAT];
        USE1(import_address_table);


        bool import_successful = true;
        if (import_data.Size > 0) {
            printf("### Loading imports...\n");
            intptr_t dest = pe_optional_header->Windows.ImageBase + import_data.VirtualAddress;
            const Structures::ImportTable::IMPORT_DIRECTORY_TABLE_HEADER* idth =
                reinterpret_cast<const Structures::ImportTable::IMPORT_DIRECTORY_TABLE_HEADER*>(dest);

            std::string library_name = reinterpret_cast<const char*>(pe_optional_header->Windows.ImageBase +
                                                                     idth->name_rva);
            std::transform(std::begin(library_name), std::end(library_name), std::begin(library_name), ::tolower);

            dest = pe_optional_header->Windows.ImageBase + idth->import_lookup_table_rva;
#if defined(CPU32)
            const Structures::ImportTable::IMPORT_LOOKUP_TABLE_ENTRY<uint32_t>* pentry =
                reinterpret_cast<const Structures::ImportTable::IMPORT_LOOKUP_TABLE_ENTRY<uint32_t>*>(dest);
#elif defined(CPU64)
            const Structures::ImportTable::IMPORT_LOOKUP_TABLE_ENTRY<uint64_t>* pentry =
                reinterpret_cast<const Structures::ImportTable::IMPORT_LOOKUP_TABLE_ENTRY<uint64_t>*>(dest);
#endif

            uintptr_t* import_addresses = reinterpret_cast<uintptr_t*>(pe_optional_header->Windows.ImageBase +
                                                                       idth->import_address_table_rva);

            for (; !pentry->End(); pentry++) {

                if (pentry->IsOrdinal())
                    throw LoaderError("All imports should be given by its name rather than ordinal number");

                if (pentry->IsName()) {

                    dest = pe_optional_header->Windows.ImageBase + pentry->HintNameRVA();
                    const Structures::ImportTable::NAME_HINT_ENTRY* phint = reinterpret_cast<const Structures::ImportTable::NAME_HINT_ENTRY*>(dest);

                    std::string function_name = phint->Name;
                    printf("  Linking %s from %s at %p... ", function_name.c_str(), library_name.c_str(),
                           reinterpret_cast<void*>(import_addresses));

                    //todo: optymalizacja -> słownik
                    bool found = false;
                    for (const WinApiFunction& wf : winapi) {
                        if (!wf.Match(library_name, function_name))
                            continue;
                        *import_addresses = wf.GetProcAddress();
                        found = true;
                        break;
                    }

                    if (found) {
                        printf(AGREEN "Ok!\n" ARESET);
                    } else {
                        printf(ARED "Not found\n" ARESET);
                        import_successful = false;
                    }
                }

                import_addresses++;
            }
        }

        if (!import_successful) {
            printf("Loading aborted.\n");
            throw LoaderError("Unable to find given routine address");
        }

        entry_point = reinterpret_cast<Core::IMAGE_ENTRY_POINT>(
            pe_optional_header->Windows.ImageBase +
            pe_optional_header->Standard.AddressOfEntryPoint);
        stack_bottom = aligned_alloc(Core::Constants::CPUMemoryPageSize,
                                     512 * Core::Constants::CPUMemoryPageSize);
        if (((intptr_t)stack_bottom & (Core::Constants::CPUMemoryPageSize - 1)) != 0)
            throw LoaderError("Allocated stack is not page-aligned");

        memset(stack_bottom, 0xcc, 512 * Core::Constants::CPUMemoryPageSize);
        stack_top = reinterpret_cast<uint8_t*>(stack_bottom) + (512 - 1) * Core::Constants::CPUMemoryPageSize;
        ptib->stack_base = stack_bottom;
        ptib->stack_limit = stack_top;

    } catch (const std::runtime_error& ex) {
        printf(ARED "Exception occured: " ARESET "%s\n", ex.what());
        return 1;
    }


    printf(ACYAN "Calling entry point %p with stack %p-%p...\n" ARESET, reinterpret_cast<void*>(entry_point),
           stack_bottom, stack_top);
    Core::EntryPointCaller(stack_top, entry_point);
    printf(ACYAN "Entry point %p has returned...\n" ARESET, reinterpret_cast<void*>(entry_point));
    printf("Exit error code: %d\n", Globals::process_exit_code);

    free(stack_bottom);
    for (const Core::Loader::PageBlockEntry& pb : allocated_pages) {
        int result = munmap(pb.GetAddress(), pb.GetPageCount());
        assert(result == 0);
    }

    printf(AWHITE "[Clean exit]\n" ARESET);
    return 0;
}

