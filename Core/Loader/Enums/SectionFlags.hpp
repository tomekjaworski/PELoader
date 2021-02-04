#if !defined(_LOADER_SectionFlags_HPP_)
#define _LOADER_SectionFlags_HPP_

namespace Core::Loader::Enums {

enum class SectionFlags : uint32_t {
    //      TYPE_REG                   = 0x00000000  // Reserved.
    //      TYPE_DSECT                 = 0x00000001  // Reserved.
    //      TYPE_NOLOAD                = 0x00000002  // Reserved.
    //      TYPE_GROUP                 = 0x00000004  // Reserved.
    TYPE_NO_PAD = 0x00000008,  // Reserved.
    //      TYPE_COPY                  = 0x00000010  // Reserved.

    CNT_CODE = 0x00000020,  // Section contains code.
    CNT_INITIALIZED_DATA = 0x00000040,  // Section contains initialized data.
    CNT_UNINITIALIZED_DATA = 0x00000080,  // Section contains uninitialized data.

    LNK_OTHER = 0x00000100,  // Reserved.
    LNK_INFO = 0x00000200,  // Section contains comments or some other type of information.
    //      TYPE_OVER                  = 0x00000400  // Reserved.
    LNK_REMOVE = 0x00000800,  // Section contents will not become part of image.
    LNK_COMDAT = 0x00001000,  // Section contents comdat.
    //                                           = 0x00002000  // Reserved.
    //      MEM_PROTECTED - Obsolete   = 0x00004000
    NO_DEFER_SPEC_EXC = 0x00004000,  // Reset speculative exceptions handling bits in the TLB entries for this section.
    GPREL = 0x00008000,  // Section content can be accessed relative to GP
    MEM_FARDATA = 0x00008000,
    //      MEM_SYSHEAP  - Obsolete    = 0x00010000
    MEM_PURGEABLE = 0x00020000,
    MEM_16BIT = 0x00020000,
    MEM_LOCKED = 0x00040000,
    MEM_PRELOAD = 0x00080000,

    ALIGN_1BYTES = 0x00100000,  //
    ALIGN_2BYTES = 0x00200000,  //
    ALIGN_4BYTES = 0x00300000,  //
    ALIGN_8BYTES = 0x00400000,  //
    ALIGN_16BYTES = 0x00500000,  // Default alignment if no others are specified.
    ALIGN_32BYTES = 0x00600000,  //
    ALIGN_64BYTES = 0x00700000,  //
    ALIGN_128BYTES = 0x00800000,  //
    ALIGN_256BYTES = 0x00900000,  //
    ALIGN_512BYTES = 0x00A00000,  //
    ALIGN_1024BYTES = 0x00B00000,  //
    ALIGN_2048BYTES = 0x00C00000,  //
    ALIGN_4096BYTES = 0x00D00000,  //
    ALIGN_8192BYTES = 0x00E00000,  //
    // Unused                                    = 0x00F00000
    ALIGN_MASK = 0x00F00000,

    LNK_NRELOC_OVFL = 0x01000000,  // Section contains extended relocations.
    MEM_DISCARDABLE = 0x02000000,  // Section can be discarded.
    MEM_NOT_CACHED = 0x04000000,  // Section is not cachable.
    MEM_NOT_PAGED = 0x08000000,  // Section is not pageable.
    MEM_SHARED = 0x10000000,  // Section is shareable.
    MEM_EXECUTE = 0x20000000,  // Section is executable.
    MEM_READ = 0x40000000,  // Section is readable.
    MEM_WRITE = 0x80000000,  // Section is writeable.
};

}

#endif // _LOADER_SectionFlags_HPP_

