#include <unistd.h> // unlink
#include <cstring>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"
#include "../../Helpers/Helper.hpp"

#include "../../Locales/LocaleBasicTypes.hpp"
#include "../NLS/NLS.hpp"


#include "Strings.hpp"


using namespace Core::WinAPI::NLS;

namespace Core::WinAPI::Strings {


/// https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar

WINBASEAPI int WINAPI
MultiByteToWideChar(
    UINT CodePage,
    DWORD dwFlags,
    LPCCH lpMultiByteStr,
    int cbMultiByte,
    LPWSTR lpWideCharStr,
    int cchWideChar
) {
    USE6(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar);
    TRACE();

    MultiByteToWideCharFlags flags = static_cast<MultiByteToWideCharFlags >(dwFlags);

    if (!IsValidCodePage(CodePage))
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);
    if (lpMultiByteStr == NULL)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);
    if (cbMultiByte == 0)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    // todo: inne strony kodowe
    if (CodePage != 1250 && CodePage != 1252)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    // todo: brak obsługi wersji composite
    if (IsFlagSet<MultiByteToWideCharFlags::MB_COMPOSITE>(flags))
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    int source_length = cbMultiByte == -1 ? ::strlen(lpMultiByteStr) + 1 : cbMultiByte;
    if (cchWideChar == 0)
        return source_length * sizeof(char16_t);

    const Locales::ANSI_TO_UCS16_ENTRY* conv_table = NULL;
    if (CodePage == 1250)
        conv_table = Locales::Conversion_Ansi_To_CP1250;
    if (CodePage == 1252)
        conv_table = Locales::Conversion_Ansi_To_CP1252;

    for (int i = 0; i < source_length; i++) {
        int ch = lpMultiByteStr[i];
        lpWideCharStr[i] = conv_table[ch].ucs16_code;
    }
    RETURN_WITH_ERROR(source_length, ErrorCode::NO_ERROR);
}


}


