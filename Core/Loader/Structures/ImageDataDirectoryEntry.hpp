#if !defined(_LOADER_ImageDataDirectoryEntry_HPP_)
#define _LOADER_ImageDataDirectoryEntry_HPP_

namespace Core::Loader::Structures
{

/// Struktura: https://docs.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-image_data_directory

struct IMAGE_DATA_DIRECTORY_ENTRY {
    uint32_t VirtualAddress;
    uint32_t Size;
};


}

#endif // _LOADER_ImageDataDirectoryEntry_HPP_
