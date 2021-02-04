#include <stdio.h>
#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "ErrorHandling.hpp"

namespace Core::WinAPI::ErrorHandling {


//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-unhandledexceptionfilter

WINBASEAPI LONG WINAPI
UnhandledExceptionFilter(
    struct _EXCEPTION_POINTERS* ExceptionInfo
) {
    USE1(ExceptionInfo);
    TRACEA("ExceptionInfo=%p", (void*)ExceptionInfo);

    TRACE_NOT_IMPLEMENTED;
    return 0;
}


//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-setunhandledexceptionfilter

WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI
SetUnhandledExceptionFilter(
    LPTOP_LEVEL_EXCEPTION_FILTER
    lpTopLevelExceptionFilter
) {
    USE1(lpTopLevelExceptionFilter);
    TRACEA("lpTopLevelExceptionFilter=%p", (void*)lpTopLevelExceptionFilter);

    TRACE_NOT_IMPLEMENTED;
    return NULL;
}


}
