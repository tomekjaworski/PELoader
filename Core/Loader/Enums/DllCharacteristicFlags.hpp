#if !defined(_LOADER_DllCharacteristicFlags_HPP_)
#define _LOADER_DllCharacteristicFlags_HPP_

namespace Core::Loader::Enums {

enum class DllCharacteristicFlags : uint16_t {
    DYNAMIC_BASE = 0x0040,    // DLL can move.
    FORCE_INTEGRITY = 0x0080,    // Code Integrity Image
    NX_COMPAT = 0x0100,    // Image is NX compatible
    NO_ISOLATION = 0x0200,    // Image understands isolation and doesn't want it
    NO_SEH = 0x0400,    // Image does not use SEH.  No SE handler may reside in this image
    NO_BIN = 0x0800,    // Do not bind this image.
    //						= 0x1000	// Reserved.
    WDM_DRIVER = 0x2000,    // Driver uses WDM model
    //						= 0x4000	// Reserved.
    TERMINAL_SERVER_AWARE = 0x8000
};

}

#endif // _LOADER_DllCharacteristicFlags_HPP_



