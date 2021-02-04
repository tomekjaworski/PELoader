#include <stdio.h>

#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "ProcesEnv.hpp"

namespace Core::WinAPI::ProcessEnv {


/// https://docs.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-setenvironmentvariablew

WINBASEAPI BOOL WINAPI
SetEnvironmentVariableW(
    LPCWSTR lpName,
    LPCWSTR lpValue
) {
    USE2(lpName, lpValue);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


