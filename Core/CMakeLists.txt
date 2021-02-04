cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        Globals.cpp Globals.hpp Host/Constants.hpp
        main.cpp

        Trace/Trace.cpp Trace/Trace.hpp
        Handles/HandleManager.cpp Handles/HandleManager.hpp Handles/HandleType.hpp Handles/HandleEntry.hpp
        UCS16/UCS16.hpp

        WinAPI/Kernel32.cpp WinAPI/Kernel32.hpp
        ProcessControlBlock.cpp ProcessControlBlock.hpp ProcessControlBlockError.hpp
        Stub/Stub.cpp Stub/Stub.hpp

        ###
        Loader/LoaderError.hpp
        Loader/Loader.hpp
        Loader/MemoryView.hpp
        Loader/PageBlockEntry.hpp

        Loader/Enums/DllCharacteristicFlags.hpp
        Loader/Enums/ImageCharacteristicFlags.hpp
        Loader/Enums/ImageDataDirectoryIndex.hpp
        Loader/Enums/ImageSubsystem.hpp
        Loader/Enums/MachineType.hpp
        Loader/Enums/PEOptionalHeaderMagic.hpp
        Loader/Enums/SectionFlags.hpp

        Loader/Structures/DosExecutableStubHeader.hpp
        Loader/Structures/ImageDataDirectoryEntry.hpp
        Loader/Structures/PE32OptionalHeader.hpp
        Loader/Structures/PE64OptionalHeader.hpp
        Loader/Structures/PEExecutableHeader.hpp
        Loader/Structures/ThreadInformationBlock.hpp
        Loader/Structures/PESectionHeader.hpp

        Loader/Structures/ImportTable/ImportDirectoryTableHeader.hpp
        Loader/Structures/ImportTable/ImportLookupTableEntry.hpp
        Loader/Structures/ImportTable/NameHintEntry.hpp

        Loader/Parsers/DosStubHeaderParser.cpp Loader/Parsers/DosStubHeaderParser.hpp
        ###

        WinApiFunction.cpp WinApiFunction.h Helpers/Helper.hpp

        Locales/LocaleBasicTypes.hpp
        Locales/ucs16_char_types.cpp Locales/ucs16_case_conversion.cpp

        Locales/ansi_cp1250.cpp Locales/ansi_cp1252.cpp
        Locales/cp1250_ansi.cpp Locales/cp1252_ansi.cpp

        FileDataProvider.cpp FileDataProvider.hpp

        ###
        Host/AnsiCodes.h
        Host/Constants.hpp
        ###
        WinAPI/ErrorCodes.hpp

        WinAPI/BasicTypes.hpp
        WinAPI/BasicMacros.hpp
        WinAPI/BasicDefinitions.hpp

        WinAPI/InternalHelpers.hpp
        ####
        WinAPI/Synchronization/Synchronization.hpp
        WinAPI/Synchronization/Sleep.cpp
        WinAPI/Synchronization/CriticalSection.cpp
        ###
        WinAPI/Console/Console.hpp
        WinAPI/Console/CP.cpp
        WinAPI/Console/Mode.cpp
        WinAPI/Console/StandardHandle.cpp
        WinAPI/Console/Write.cpp
        ###
        WinAPI/Debug/Debug.hpp
        WinAPI/Debug/Break.cpp
        WinAPI/Debug/IsPresent.cpp
        WinAPI/Debug/Printers.cpp
        ###
        WinAPI/ErrorHandling/ErrorHandling.hpp
        WinAPI/ErrorHandling/SetExceptionFilter.cpp
        WinAPI/ErrorHandling/LastError.cpp
        WinAPI/ErrorHandling/Raise.cpp
        ###
        WinAPI/File/File.hpp
        WinAPI/File/Write.cpp
        WinAPI/File/Create.cpp
        WinAPI/File/Delete.cpp
        WinAPI/File/FilePointer.cpp
        WinAPI/File/Find.cpp
        WinAPI/File/Flush.cpp
        WinAPI/File/Read.cpp
        WinAPI/File/Size.cpp
        WinAPI/File/Type.cpp
        ###
        WinAPI/Handle/Handle.hpp
        WinAPI/Handle/Close.cpp
        ###
        WinAPI/Heap/Heap.hpp
        WinAPI/Heap/Alloc.cpp
        ###
        WinAPI/Interlocked/Interlocked.hpp
        WinAPI/Interlocked/SingleLinkedList.cpp
        ###
        WinAPI/LibLoader/LibLoader.hpp
        WinAPI/LibLoader/FreeLibrary.cpp
        WinAPI/LibLoader/Load.cpp
        WinAPI/LibLoader/ModuleFileName.cpp
        WinAPI/LibLoader/ModuleHandle.cpp
        WinAPI/LibLoader/ProcAddress.cpp
        ###
        WinAPI/NLS/NLS.hpp
        WinAPI/NLS/CodePage.cpp
        ###
        WinAPI/ProcessEnvironment/ProcesEnv.hpp
        WinAPI/ProcessEnvironment/CommandLine.cpp
        WinAPI/ProcessEnvironment/Strings.cpp
        WinAPI/ProcessEnvironment/Variables.cpp
        ###
        WinAPI/ProcessThread/ProcessThread.hpp
        WinAPI/ProcessThread/ExitProcess.cpp
        WinAPI/ProcessThread/GetCurrentProcess.cpp
        WinAPI/ProcessThread/GetCurrentThread.cpp
        WinAPI/ProcessThread/LocalStorage.cpp
        WinAPI/ProcessThread/ProcessorFeatures.cpp
        WinAPI/ProcessThread/StartupInfo.cpp
        WinAPI/ProcessThread/Terminate.cpp
        ###
        WinAPI/Profile/Profile.hpp
        WinAPI/Profile/Query.cpp
        ###
        WinAPI/Strings/Strings.hpp
        WinAPI/Strings/Compare.cpp
        WinAPI/Strings/LocaleMapString.cpp
        WinAPI/Strings/MultiByteToWideChar.cpp
        WinAPI/Strings/WideCharToMultiByte.cpp
        WinAPI/Strings/StringType.cpp
        ###
        WinAPI/Synchronization/Synchronization.hpp
        WinAPI/Synchronization/CriticalSection.cpp
        WinAPI/Synchronization/Sleep.cpp
        ###
        WinAPI/SysInfo/SysInfo.hpp
        WinAPI/SysInfo/SystemTimeAsFileTime.cpp
        ###
        WinAPI/WinNT/WinNT.hpp
        WinAPI/WinNT/CaptureContext.cpp
        WinAPI/WinNT/FunctionLookup.cpp
        WinAPI/WinNT/Unwind.cpp
        WinAPI/WinNT/VirtualUnwind.cpp
        ###
        WinAPI/Util/Util.hpp
        WinAPI/Util/Pointers.cpp
        ###

        )


add_executable(Core32 ${SOURCE_FILES})


target_compile_options(Core32 PUBLIC
        -masm=intel
        -m32
        -Wall
        -Wextra
        -pedantic
        -D_GNU_SOURCE
        -Wno-format
)
target_link_options(Core32 PUBLIC
        -Wl,-z,stack-size=33554432
        -Xlinker -Map=output.map
        -Xlinker -m32
)

target_link_libraries(Core32 m rt pthread)





add_executable(Core64 ${SOURCE_FILES})


target_compile_options(Core64 PUBLIC
        -masm=intel
        -m64
        -Wall
        -Wextra
        -pedantic
        -D_GNU_SOURCE
        -Wno-format
        )
target_link_options(Core64 PUBLIC
        -Wl,-z,stack-size=33554432
        -Xlinker -Map=output.map
        -Xlinker -m64
        )

target_link_libraries(Core64 m rt pthread)

