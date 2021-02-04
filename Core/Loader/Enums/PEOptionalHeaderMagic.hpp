#if !defined(_LOADER_PEOptionalHeaderMagic_HPP_)
#define _LOADER_PEOptionalHeaderMagic_HPP_

namespace Core::Loader::Enums {


enum class PEOptionalHeaderMagic : uint16_t {
    NT_HDR32 = 0x10b,
    NT_HDR64 = 0x20b,
    ROM_HDR = 0x107
};

}

#endif // _LOADER_PEOptionalHeaderMagic_HPP_

