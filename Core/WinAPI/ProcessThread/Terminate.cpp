#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "ProcessThread.hpp"

namespace Core::WinAPI::ProcessThread {


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-terminateprocess

WINBASEAPI BOOL WINAPI
TerminateProcess(
    HANDLE hProcess,
    UINT uExitCode
) {
    USE2(hProcess, uExitCode);
    TRACEA("hProcess=%p, uExitCode=%u", (void*)hProcess, uExitCode);

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


