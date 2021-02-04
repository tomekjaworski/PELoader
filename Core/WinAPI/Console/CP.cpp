#include "../../Trace/Trace.hpp"
#include "../BasicTypes.hpp"
#include "Console.hpp"

#include "../InternalHelpers.hpp"

namespace Core::WinAPI::Console {

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/console/getconsolecp
WINBASEAPI UINT WINAPI
GetConsoleCP(
    VOID
) {
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return 0;
}


}