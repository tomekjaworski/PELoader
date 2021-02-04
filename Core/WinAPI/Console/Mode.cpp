#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "Console.hpp"

namespace Core::WinAPI::Console {



//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/console/getconsolemode

WINBASEAPI BOOL WINAPI
GetConsoleMode(
   HANDLE hConsoleHandle,
   LPDWORD lpMode
) {
    USE2(hConsoleHandle, lpMode);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}

//
// ######################################################
//


}