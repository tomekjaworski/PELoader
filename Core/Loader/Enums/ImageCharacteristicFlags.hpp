#if !defined(_LOADER_ImageCharacteristicFlags_HPP_)
#define _LOADER_ImageCharacteristicFlags_HPP_

namespace Core::Loader::Enums {


enum class ImageCharacteristicFlags : uint16_t {
    RELOCS_STRIPPED = 0x0001,  // Relocation info stripped from file.
    EXECUTABLE_IMAGE = 0x0002,  // File is executable  (i.e. no unresolved externel references).
    LINE_NUMS_STRIPPED = 0x0004,  // Line nunbers stripped from file.
    LOCAL_SYMS_STRIPPED = 0x0008,  // Local symbols stripped from file.
    AGGRESIVE_WS_TRIM = 0x0010,  // Agressively trim working set
    LARGE_ADDRESS_AWARE = 0x0020,  // App can handle >2gb addresses
    BYTES_REVERSED_LO = 0x0080,  // Bytes of machine word are reversed.
    _32BIT_MACHINE = 0x0100,  // 32 bit word machine.
    DEBUG_STRIPPED = 0x0200,  // Debugging info stripped from file in .DBG file
    REMOVABLE_RUN_FROM_SWAP = 0x0400,  // If IMAGE is on removable media, copy and run from the swap file.
    NET_RUN_FROM_SWAP = 0x0800,  // If IMAGE is on Net, copy and run from the swap file.
    SYSTEM = 0x1000,  // System File.
    DLL = 0x2000,  // File is a DLL.
    UP_SYSTEM_ONLY = 0x4000,  // File should only be run on a UP machine
    BYTES_REVERSED_HI = 0x8000,  // Bytes of machine word are reversed.
};

}

#endif // _LOADER_ImageCharacteristicFlags_HPP_

