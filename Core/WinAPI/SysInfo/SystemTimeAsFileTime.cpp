#include <ctime>
#include <stdint.h>

#include "../BasicTypes.hpp"
#include "../../Trace/Trace.hpp"

#include "SysInfo.hpp"


#define WINDOWS_TICK 10000000
#define SEC_TO_UNIX_EPOCH 11644473600LL

namespace Core::WinAPI::SysInfo {

//
//

/// https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getsystemtimeasfiletime
/// https://docs.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-filetime

WINBASEAPI VOID WINAPI
GetSystemTimeAsFileTime(
    LPFILETIME lpSystemTimeAsFileTime
) {
    TRACEA("lpSystemTimeAsFileTime=%p", (void*)lpSystemTimeAsFileTime);
    uint64_t now = static_cast<uint64_t>(time(NULL));
    uint64_t ft_utc = WINDOWS_TICK * (now + SEC_TO_UNIX_EPOCH);

    lpSystemTimeAsFileTime->dwLowDateTime = ft_utc & 0xFFFFFFFF;
    lpSystemTimeAsFileTime->dwHighDateTime = (ft_utc >> 32) & 0xFFFFFFFF;
}


}


