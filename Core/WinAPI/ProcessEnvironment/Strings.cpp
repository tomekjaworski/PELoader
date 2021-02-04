#include <stdio.h>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "ProcesEnv.hpp"

namespace Core::WinAPI::ProcessEnv {


/// https://docs.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-getenvironmentstringsw

WINBASEAPI LPWCH WINAPI
GetEnvironmentStringsW(
    VOID
) {
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    RETURN_WITH_ERROR(NULL, ErrorCode::ERROR_CALL_NOT_IMPLEMENTED);
}


//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-freeenvironmentstringsw

WINBASEAPI BOOL WINAPI
FreeEnvironmentStringsW(
    LPWCH penv
) {
    USE1(penv);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


