#if !defined(_LOADER_PE32OptionalHeader_HPP_)
#define _LOADER_PE32OptionalHeader_HPP_

namespace Core::Loader::Structures {
namespace Enums = Core::Loader::Enums;

/// Struktura: https://docs.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-image_optional_header32
/// Dokumentacja: https://docs.microsoft.com/en-us/windows/win32/debug/pe-format#optional-header-image-only

struct PE32_OPTIONAL_HEADER {

    struct {
        Enums::PEOptionalHeaderMagic Magic;
        uint8_t MajorLinkerVersion;
        uint8_t MinorLinkerVersion;
        uint32_t SizeOfCode;
        uint32_t SizeOfInitializedData;
        uint32_t SizeOfUninitializedData;
        uint32_t AddressOfEntryPoint;
        uint32_t BaseOfCode;
        uint32_t BaseOfData;
    } Standard;

    //
    // NT additional fields.
    //

    struct {
        uint32_t ImageBase;
        uint32_t SectionAlignment;
        uint32_t FileAlignment;
        uint16_t MajorOperatingSystemVersion;
        uint16_t MinorOperatingSystemVersion;
        uint16_t MajorImageVersion;
        uint16_t MinorImageVersion;
        uint16_t MajorSubsystemVersion;
        uint16_t MinorSubsystemVersion;
        uint32_t Win32VersionValue;
        uint32_t SizeOfImage;
        uint32_t SizeOfHeaders;
        uint32_t CheckSum;
        Enums::ImageSubsystem Subsystem;
        Enums::DllCharacteristicFlags DllCharacteristics;
        uint32_t SizeOfStackReserve;
        uint32_t SizeOfStackCommit;
        uint32_t SizeOfHeapReserve;
        uint32_t SizeOfHeapCommit;
        uint32_t LoaderFlags;
        uint32_t NumberOfRvaAndSizes;
    } Windows;

    Structures::IMAGE_DATA_DIRECTORY_ENTRY DataDirectory[ImageDataDirectoryEntries];
};

static_assert(sizeof(PE32_OPTIONAL_HEADER) == 30 + 66 + 16 * 8);

}

#endif // _LOADER_PE32OptionalHeader_HPP_