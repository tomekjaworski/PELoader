#if !defined(_LOADER_PEExecutableHeader_HPP_)
#define _LOADER_PEExecutableHeader_HPP_

namespace Core::Loader::Structures {
namespace Enums = Core::Loader::Enums;

/// Struktura: https://docs.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-image_file_header

constexpr uint64_t PEExecutableHeaderMagic = 0x00004550;

struct PE_EXECUTABLE_HEADER {
    uint32_t Magic;
    Enums::MachineType Machine;
    uint16_t NumberOfSections;
    uint32_t TimeDateStamp;
    uint32_t PointerToSymbolTable;
    uint32_t NumberOfSymbols;
    uint16_t SizeOfOptionalHeader;
    Enums::ImageCharacteristicFlags Characteristics;
};

static_assert(sizeof(PE_EXECUTABLE_HEADER) == 24);

}


#endif // _LOADER_PEExecutableHeader_HPP_


