#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../BasicMacros.hpp"
#include "../../Trace/Trace.hpp"

#include "ErrorHandling.hpp"

namespace Core::WinAPI::ErrorHandling {


/// https://docs.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception

WINBASEAPI VOID WINAPI
RaiseException(
    DWORD dwExceptionCode,
    DWORD dwExceptionFlags,
    DWORD nNumberOfArguments,
    CONST ULONG_PTR* lpArguments
) {
    USE4(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
}

}


