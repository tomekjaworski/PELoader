#include <sys/types.h>
#include <unistd.h>

#include "../BasicTypes.hpp"
#include "../BasicDefinitions.hpp"
#include "../../Trace/Trace.hpp"

#include "ProcessThread.hpp"

namespace Core::WinAPI::ProcessThread {


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess
WINBASEAPI HANDLE WINAPI
GetCurrentProcess(
    VOID
) {
    TRACE();
    TRACE_NOT_IMPLEMENTED;
    return CURRENT_PROCESS_HANDLE;
}


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessid

WINBASEAPI DWORD WINAPI
GetCurrentProcessId(
    VOID
) {
    TRACE();
    pid_t pid = getpid();
    DWORD dwid = static_cast<DWORD>(pid);
    return dwid;
}


}


