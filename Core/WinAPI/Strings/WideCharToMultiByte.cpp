#include <cassert>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "../../Locales/LocaleBasicTypes.hpp"
#include "../../UCS16/UCS16.hpp"
#include "../NLS/NLS.hpp"

#include "Strings.hpp"

using namespace Core::WinAPI::NLS;


namespace Core::WinAPI::Strings {

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte

WINBASEAPI int WINAPI
WideCharToMultiByte(
    UINT CodePage,
    DWORD dwFlags,
    LPCWCH lpWideCharStr,
    int cchWideChar,
    LPSTR lpMultiByteStr,
    int cbMultiByte,
    LPCCH lpDefaultChar,
    LPBOOL lpUsedDefaultChar
) {
    USE8(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cbMultiByte, lpDefaultChar, lpUsedDefaultChar);
    TRACE();

    WideCharToMultiByteFlags flags = static_cast<WideCharToMultiByteFlags>(dwFlags);

    if (flags != WideCharToMultiByteFlags::None)
        RETURN_WITH_ERROR(0, ErrorCode::ERROR_INVALID_PARAMETER);
    if (!IsValidCodePage(CodePage))
        RETURN_WITH_ERROR(0, ErrorCode::ERROR_INVALID_PARAMETER);

    const Locales::UCS16_TO_ANSI_ENTRY* table = nullptr;
    if (CodePage == 1250)
        table = Locales::Conversion_CP1250_To_Ansi;
    if (CodePage == 1252)
        table = Locales::Conversion_CP1252_To_Ansi;

    CPINFO cpinfo;
    GetCPInfo(CodePage, &cpinfo);

    int source_length = cchWideChar == -1 ? UCS16::strlen(lpWideCharStr) + 1 : cchWideChar;
    if (cbMultiByte == 0)
        return source_length;

    bool default_used = false;
    for (int i = 0; i < source_length; i++) {
        int ch = lpWideCharStr[i];
        assert(ch >= 0);
        const Locales::UCS16_TO_ANSI_ENTRY* pentry = &table[ch];
        if (pentry->ansi == -1) {
            default_used = true;
            if (lpDefaultChar != nullptr)
                lpMultiByteStr[i] = *lpDefaultChar;
            else
                lpMultiByteStr[i] = static_cast<CHAR>(cpinfo.DefaultChar[0]);
        } else
            lpMultiByteStr[i] = static_cast<CHAR>(pentry->ansi);
    }

    if (default_used && lpUsedDefaultChar != nullptr)
        *lpUsedDefaultChar = TRUE;

    RETURN_WITH_ERROR(source_length, ErrorCode::NO_ERROR);
}

}


