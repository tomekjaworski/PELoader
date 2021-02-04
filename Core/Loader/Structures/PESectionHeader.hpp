#if !defined(_LOADER_PESectionHeader_HPP_)
#define _LOADER_PESectionHeader_HPP_

/// Struktura: https://docs.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-image_section_header

namespace Core::Loader::Structures {
namespace Enums = Core::Loader::Enums;

constexpr int SectionNameSize = 8;

struct PE_SECTION_HEADER {
    char Name[SectionNameSize];
    union {
        uint32_t PhysicalAddress;
        uint32_t VirtualSize;
    } Misc;
    uint32_t VirtualAddress;
    uint32_t SizeOfRawData;
    uint32_t PointerToRawData;
    uint32_t PointerToRelocations;
    uint32_t PointerToLinenumbers;
    uint16_t NumberOfRelocations;
    uint16_t NumberOfLinenumbers;
    Enums::SectionFlags Characteristics;
};

static_assert(sizeof(PE_SECTION_HEADER) == 40);

}

#endif // _LOADER_PESectionHeader_HPP_
