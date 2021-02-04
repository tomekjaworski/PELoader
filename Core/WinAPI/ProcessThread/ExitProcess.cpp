#include <csetjmp>

#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#define WANT_PROCESS_EXIT_POINT

#include "../../Globals.hpp"

#undef WANT_PROCESS_EXIT_POINT


#include "ProcessThread.hpp"

namespace Core::WinAPI::ProcessThread {



//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitprocess

WINBASEAPI DECLSPEC_NORETURN VOID WINAPI
ExitProcess(
    UINT uExitCode
) {
    USE1(uExitCode);
    TRACEA("uExitCode=%u", uExitCode);

    Globals::process_exit_code = uExitCode;
    std::longjmp(Globals::process_exit_point, 42);
}


}


