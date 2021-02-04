#include <cassert>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "../../Locales/LocaleBasicTypes.hpp"
#include "../../UCS16/UCS16.hpp"

#include "Strings.hpp"


namespace Core::WinAPI::Strings {

/// https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-lcmapstringw
WINBASEAPI int WINAPI
LCMapStringW(
    LCID Locale,
    DWORD dwMapFlags,
    LPCWSTR lpSrcStr,
    int cchSrc,
    LPWSTR lpDestStr,
    int cchDest
) {
    USE6(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest);
    TRACE();

    LCMapStringFlags flags = static_cast<LCMapStringFlags>(dwMapFlags);

    // todo: bardzo uproszczona wersja, z pominięciem koncepcji flag
    if (flags != LCMapStringFlags::LCMAP_LOWERCASE && flags != LCMapStringFlags::LCMAP_UPPERCASE)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    if (cchSrc <= 0)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    int source_length = cchSrc == -1 ? UCS16::strlen(lpSrcStr) + 1 : cchSrc;

    if (cchDest == 0)
        return source_length; // ok tylko dla UPPER|LOWER

    if (flags == LCMapStringFlags::LCMAP_LOWERCASE)
        for (int i = 0; i < source_length; i++) {
            int ch = lpSrcStr[i];
            assert(ch >= 0);

            lpDestStr[i] = Locales::ucs16_case_table[ch].lower;
        }
    if (flags == LCMapStringFlags::LCMAP_UPPERCASE)
        for (int i = 0; i < source_length; i++) {
            int ch = lpSrcStr[i];
            assert(ch >= 0);
            lpDestStr[i] = Locales::ucs16_case_table[ch].upper;
        }

    RETURN_WITH_ERROR(source_length, ErrorCode::NO_ERROR);
}


}


