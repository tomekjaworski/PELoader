#if !defined(_LOADER_MACHINE_TYPE_HPP_)
#define _LOADER_MACHINE_TYPE_HPP_

namespace Core::Loader::Enums {

enum class MachineType : uint16_t {
    UNKNOWN = 0x0000,
    I386 = 0x014c,  // Intel 386.
    R3000 = 0x0162,  // MIPS little-endian, = 0x160 big-endian
    R4000 = 0x0166,  // MIPS little-endian
    R10000 = 0x0168,  // MIPS little-endian
    WCEMIPSV2 = 0x0169,  // MIPS little-endian WCE v2
    ALPHA = 0x0184,  // Alpha_AXP
    SH3 = 0x01a2,  // SH3 little-endian
    SH3DSP = 0x01a3,
    SH3E = 0x01a4,  // SH3E little-endian
    SH4 = 0x01a6,  // SH4 little-endian
    SH5 = 0x01a8,  // SH5
    ARM = 0x01c0,  // ARM Little-Endian
    THUMB = 0x01c2,
    AM33 = 0x01d3,
    POWERPC = 0x01F0,  // IBM PowerPC Little-Endian
    POWERPCFP = 0x01f1,
    IA64 = 0x0200,  // Intel 64
    MIPS16 = 0x0266,  // MIPS
    ALPHA64 = 0x0284,  // ALPHA64
    MIPSFPU = 0x0366,  // MIPS
    MIPSFPU16 = 0x0466,  // MIPS
    AXP64 = ALPHA64,
    TRICORE = 0x0520,  // Infineon
    CEF = 0x0CEF,
    EBC = 0x0EBC,  // EFI Byte Code
    AMD64 = 0x8664,  // AMD64 (K8)
    M32R = 0x9041,  // M32R little-endian
    CEE = 0xC0EE,
};

}

#endif // _LOADER_MACHINE_TYPE_HPP_
