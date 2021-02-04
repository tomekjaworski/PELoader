#include <unistd.h>
#include "../BasicTypes.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Host/AnsiCodes.h"
#include "../../Trace/Trace.hpp"

#include "Debug.hpp"

namespace Core::WinAPI::Debug {

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-outputdebugstringa
WINBASEAPI VOID WINAPI
OutputDebugStringA(
    LPCSTR lpOutputString
) {
    USE1(lpOutputString);
    TRACEA("lpOutputString='%s'", lpOutputString);

    if (lpOutputString == nullptr)
        lpOutputString = "(null)";

    char buffer[1024];
    int bytes = snprintf(buffer, sizeof(buffer), AGREEN "DEBUG: " ARESET "%s\n", lpOutputString);
    write(STDOUT_FILENO, buffer, bytes);
}

}