#if !defined(_LOADER_ImageDataDirectoryIndex_HPP_)
#define _LOADER_ImageDataDirectoryIndex_HPP_

namespace Core::Loader::Enums {


struct ImageDataDirectoryIndex {
    constexpr static int EXPORT = 0;   // Export Directory
    constexpr static int IMPORT = 1;   // Import Directory
    constexpr static int RESOURCE = 2;   // Resource Directory
    constexpr static int EXCEPTION = 3;   // Exception Directory
    constexpr static int SECURITY = 4;   // Security Directory
    constexpr static int BASERELOC = 5;   // Base Relocation Table
    constexpr static int DEBUG = 6;   // Debug Directory
    //constexpr static int //      COPYRIGHT       7   // (X86 usage)
    constexpr static int ARCHITECTURE = 7;   // Architecture Specific Data
    constexpr static int GLOBALPTR = 8;   // RVA of GP
    constexpr static int TLS = 9;   // TLS Directory
    constexpr static int LOAD_CONFIG = 10;   // Load Configuration Directory
    constexpr static int BOUND_IMPORT = 11;   // Bound Import Directory in headers
    constexpr static int IAT = 12;   // Import Address Table
    constexpr static int DELAY_IMPORT = 13;   // Delay Load Import Descriptors
    constexpr static int COM_DESCRIPTOR = 14;   // COM Runtime descriptor
};


}

#endif // _LOADER_ImageDataDirectoryIndex_HPP_

