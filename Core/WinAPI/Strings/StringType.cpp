#include <cstring>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "../../Locales/LocaleBasicTypes.hpp"
#include "../../UCS16/UCS16.hpp"

#include "Strings.hpp"


namespace Core::WinAPI::Strings {


enum class GetStringTypeType : DWORD {
    CT_CTYPE1 = 0x00000001,
    CT_CTYPE2 = 0x00000002,
    CT_CTYPE3 = 0x00000004,
};


/// https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-getstringtypew

WINBASEAPI BOOL WINAPI
GetStringTypeW(
    DWORD dwInfoType,
    LPCWCH lpSrcStr,
    int cchSrc,
    LPWORD lpCharType
) {
    USE4(dwInfoType, lpSrcStr, cchSrc, lpCharType);
    TRACE();

    GetStringTypeType type = static_cast<GetStringTypeType >(dwInfoType);

    if (lpSrcStr == NULL)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);
    if (type != GetStringTypeType::CT_CTYPE1 && type != GetStringTypeType::CT_CTYPE2 &&
        type != GetStringTypeType::CT_CTYPE3)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    int source_length = cchSrc < 0 ? UCS16::strlen(lpSrcStr) + 1 : cchSrc;

    if (type == GetStringTypeType::CT_CTYPE1)
        for (int i = 0; i < source_length; i++)
            lpCharType[i] = Locales::ucs16_type_table[i].c1;
    if (type == GetStringTypeType::CT_CTYPE2)
        for (int i = 0; i < source_length; i++)
            lpCharType[i] = Locales::ucs16_type_table[i].c2;
    if (type == GetStringTypeType::CT_CTYPE3)
        for (int i = 0; i < source_length; i++)
            lpCharType[i] = Locales::ucs16_type_table[i].c3;

    return FALSE;
}


}


