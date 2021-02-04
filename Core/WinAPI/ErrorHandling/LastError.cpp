#include "../BasicTypes.hpp"
#include "../../Globals.hpp"
#include "../BasicMacros.hpp"
#include "../../Trace/Trace.hpp"

#include "ErrorHandling.hpp"

namespace Globals = Core::Globals;
namespace Core::WinAPI::ErrorHandling {


//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror

WINBASEAPI DWORD WINAPI
GetLastError(
    VOID
) {
    TRACE();
    return static_cast<DWORD>(Globals::last_error_code);
}


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror

WINBASEAPI VOID WINAPI
SetLastError(
    DWORD dwErrCode
) {
    TRACEA("dwErrCode=%u", dwErrCode);
    Globals::last_error_code = static_cast<ErrorCode>(dwErrCode);
}


}


