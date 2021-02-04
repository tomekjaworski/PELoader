#if !defined(_LOADER_ImportDirectoryTableHeader_HPP_)
#define _LOADER_ImportDirectoryTableHeader_HPP_

namespace Core::Loader::Structures::ImportTable {

struct IMPORT_DIRECTORY_TABLE_HEADER {
    uint32_t import_lookup_table_rva;
    uint32_t timestamp;
    uint32_t forwarder_chain;
    uint32_t name_rva;
    uint32_t import_address_table_rva;
};

}

#endif // _LOADER_ImportDirectoryTableHeader_HPP_

