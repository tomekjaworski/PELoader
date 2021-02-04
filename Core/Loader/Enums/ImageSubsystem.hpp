#if !defined(_LOADER_ImageSubsystem_HPP_)
#define _LOADER_ImageSubsystem_HPP_

namespace Core::Loader::Enums {

enum class ImageSubsystem : uint16_t {
    UNKNOWN = 0,   // Unknown subsystem.
    NATIVE = 1,   // Image doesn't require a subsystem.
    WINDOWS_GUI = 2,   // Image runs in the Windows GUI subsystem.
    WINDOWS_CUI = 3,   // Image runs in the Windows character subsystem.
    OS2_CUI = 5,   // image runs in the OS/2 character subsystem.
    POSIX_CUI = 7,   // image runs in the Posix character subsystem.
    NATIVE_WINDOWS = 8,   // image is a native Win9x driver.
    WINDOWS_CE_GUI = 9,   // Image runs in the Windows CE subsystem.
    EFI_APPLICATION = 10,  //
    EFI_BOOT_SERVICE_DRIVER = 11,  //
    EFI_RUNTIME_DRIVER = 12,  //
    EFI_ROM = 13,
    XBOX = 14,
    WINDOWS_BOOT_APPLICATION = 16
};

}

#endif // _LOADER_ImageSubsystem_HPP_


