#include "../BasicTypes.hpp"
#include "../../Trace/Trace.hpp"

#include "Debug.hpp"

namespace Core::WinAPI::Debug {

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-isdebuggerpresent

WINBASEAPI BOOL WINAPI
IsDebuggerPresent(
    VOID
) {
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return TRUE;
}


}