#include "../BasicTypes.hpp"
#include "../../Trace/Trace.hpp"

#include "Debug.hpp"

namespace Core::WinAPI::Debug {


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-debugbreak
WINBASEAPI VOID WINAPI
DebugBreak(VOID) {
    TRACE();
    asm("xchg ax, ax");
    asm("int 0x3");
    return;
}

}