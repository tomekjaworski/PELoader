#include <cstring>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "NLS.hpp"

namespace Core::WinAPI::NLS {



//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-isvalidcodepage

WINBASEAPI BOOL WINAPI
IsValidCodePage(
    UINT CodePage
) {
    USE1(CodePage);
    TRACE();

    if (CodePage == 1250)
        return TRUE;
    if (CodePage == 1252)
        return TRUE;

    return FALSE;
}

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getacp
WINBASEAPI UINT WINAPI
GetACP(
    VOID
) {
    TRACE();
    return 1250; //todo: ?
}

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getoemcp

WINBASEAPI UINT WINAPI
GetOEMCP(
    void
) {
    TRACE();
    return 1250; //todo: ?
}


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getcpinfo
WINBASEAPI BOOL WINAPI
GetCPInfo(
    UINT CodePage,
    LPCPINFO lpCPInfo
) {
    USE2(CodePage, lpCPInfo);
    TRACE();

    if (!IsValidCodePage(CodePage))
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);
    if (lpCPInfo == NULL)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    if (CodePage == 1250 || CodePage == 1252) {
        memset(lpCPInfo, 0x00, sizeof(CPINFO));
        lpCPInfo->MaxCharSize = 1;
        lpCPInfo->DefaultChar[0] = '?';
        RETURN_WITH_ERROR(TRUE, ErrorCode::NO_ERROR);
    }
    RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_CALL_NOT_IMPLEMENTED);
}


}


