#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "Console.hpp"

namespace Core::WinAPI::Console {

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/console/writeconsole
WINBASEAPI BOOL WINAPI
WriteConsoleW(
    HANDLE hConsoleOutput,
    CONST VOID* lpBuffer,
    DWORD nNumberOfCharsToWrite,
    LPDWORD lpNumberOfCharsWritten,
    LPVOID lpReserved
) {
    USE5(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}

}