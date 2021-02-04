#include <stdio.h>
#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../BasicDefinitions.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "Console.hpp"

namespace Core::WinAPI::Console {


//
// ######################################################
//

enum class StandardHandleType : DWORD {
    STD_INPUT_HANDLE = (DWORD)(-10),
    STD_OUTPUT_HANDLE = (DWORD)(-11),
    STD_ERROR_HANDLE = (DWORD)(-12)
};

/// https://docs.microsoft.com/en-us/windows/console/getstdhandle

WINBASEAPI HANDLE WINAPI
GetStdHandle(
    DWORD nStdHandle
) {
    USE1(nStdHandle);
    TRACE();

    StandardHandleType type = static_cast<StandardHandleType>(nStdHandle);
    if (type == StandardHandleType::STD_INPUT_HANDLE)
        RETURN_WITH_ERROR((HANDLE)(stdin), ErrorCode::NO_ERROR);
    if (type == StandardHandleType::STD_OUTPUT_HANDLE)
        RETURN_WITH_ERROR((HANDLE)(stdout), ErrorCode::NO_ERROR);
    if (type == StandardHandleType::STD_ERROR_HANDLE)
        RETURN_WITH_ERROR((HANDLE)(stderr), ErrorCode::NO_ERROR);
    RETURN_WITH_ERROR(INVALID_HANDLE_VALUE, ErrorCode::ERROR_INVALID_HANDLE);
}


//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/console/setstdhandle

WINBASEAPI BOOL WINAPI
SetStdHandle(
    DWORD nStdHandle,
    HANDLE hHandle
) {
    USE2(nStdHandle, hHandle);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}