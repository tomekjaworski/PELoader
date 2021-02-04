#include <unistd.h>
#include <algorithm>

#include "../BasicTypes.hpp"
#include "../../Trace/Trace.hpp"
#include "../InternalHelpers.hpp"


#include "Synchronization.hpp"

namespace Core::WinAPI::Synchronization {


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-sleep
WINBASEAPI VOID WINAPI
Sleep(
    DWORD dwMilliseconds
) {

    //
    USE1(dwMilliseconds);
    TRACEA("dwMilliseconds=%d", dwMilliseconds);

    uint64_t usec = dwMilliseconds * 1000;
    while (usec > 0) {
        uint64_t u = std::min<uint64_t>(usec, 1e6);
        usleep(u);
        usec -= u;
    }
    return;
}

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-sleepex
WINBASEAPI DWORD WINAPI
SleepEx(
    DWORD dwMilliseconds,
    BOOL bAlertable
) {
    //
    USE2(dwMilliseconds, bAlertable);
    TRACEA("dwMilliseconds=%d, bAlertable=%d", dwMilliseconds, bAlertable);

    sleep(dwMilliseconds * 1000); // todo: bAlertable
    return 0;
}

}