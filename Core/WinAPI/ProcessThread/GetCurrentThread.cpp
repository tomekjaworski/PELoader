#include <unistd.h>
#include <sys/syscall.h>

#include "../BasicTypes.hpp"
#include "../../Trace/Trace.hpp"

#include "ProcessThread.hpp"

namespace Core::WinAPI::ProcessThread {

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid

WINBASEAPI DWORD WINAPI
GetCurrentThreadId(
    VOID
) {
    TRACE();

    pid_t id = syscall(__NR_gettid);
    DWORD dwid = static_cast<DWORD>(id);
    return dwid;
}


}


