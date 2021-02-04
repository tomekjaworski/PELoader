#include "../BasicTypes.hpp"

#include "Util.hpp"

namespace Core::WinAPI::Util {

WINBASEAPI PVOID WINAPI EncodePointer(PVOID Ptr) {
    // Radosna twórczość ;)
#if defined(CPU32)
    uintptr_t ptr = reinterpret_cast<uintptr_t>(Ptr);
    ptr ^= 0xdeadbeef;
#elif defined(CPU64)
    uintptr_t ptr = reinterpret_cast<uintptr_t>(Ptr);
    ptr ^= 0x1337c0dea7badd11;
#endif
    return reinterpret_cast<PVOID>(ptr);
}

//
// ##########################
//

WINBASEAPI PVOID WINAPI DecodePointer(PVOID Ptr) {
    return EncodePointer(Ptr); // to samo, tylko odwrotnie
}


}


