#if !defined(_DOS_EXECUTABLE_HEADER_HPP_)
#define _DOS_EXECUTABLE_HEADER_HPP_

namespace Core::Loader::Structures {

constexpr uint16_t DosHeaderMagic = 0x5A4D; // MZ

struct DOS_EXECUTABLE_STUB_HEADER {
    uint16_t magic;
    uint16_t bytes_on_last_page;
    uint16_t pages_in_file;
    uint16_t relocations_count;
    uint16_t paragraphs_in_header;
    uint16_t minimum_memory;
    uint16_t maximum_memory;
    uint16_t reg_sp;
    uint16_t checksum;
    uint16_t reg_ip;
    uint16_t reg_cs;
    uint16_t reloc_table_offset;
    uint16_t overlay_number;

    struct {
        uint16_t reserved1[4];
        uint16_t oem_id;
        uint16_t oem_info;
        uint16_t reserved3[10];
        uint32_t offset;
    } pe;
};

static_assert(sizeof(DOS_EXECUTABLE_STUB_HEADER) == 64);



}

#endif // _DOS_EXECUTABLE_HEADER_HPP_)

