#include <string.h>

#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "ProcessThread.hpp"

namespace Core::WinAPI::ProcessThread {



//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getstartupinfow
WINBASEAPI VOID WINAPI
GetStartupInfoW(
    LPSTARTUPINFOW lpStartupInfo
) {
    USE1(lpStartupInfo);
    TRACEA("lpStartupInfo=%p", (void*)lpStartupInfo);

    memset(lpStartupInfo, 0, sizeof(STARTUPINFOW));
    lpStartupInfo->cb = sizeof(STARTUPINFOW);
    lpStartupInfo->lpDesktop = u"Winsta0\\Default";
    lpStartupInfo->lpTitle = u"Tytuł okna konsoli...";

    lpStartupInfo->hStdInput = (HANDLE)1;
    lpStartupInfo->hStdError = (HANDLE)1;
    return;
}


}


