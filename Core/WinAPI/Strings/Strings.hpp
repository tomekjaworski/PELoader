#if !defined(_WINAPI_STRINGS_HPP_)
#define _WINAPI_STRINGS_HPP_

namespace Core::WinAPI::Strings {

WINBASEAPI int WINAPI
CompareStringW(LCID Locale, DWORD dwCmpFlags, PCNZWCH lpString1, int cchCount1, PCNZWCH lpString2, int cchCount2);

//
//

enum class LCMapStringFlags : DWORD {
    LCMAP_LOWERCASE = 0x00000100,
    LCMAP_UPPERCASE = 0x00000200,
};

/// https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-lcmapstringw
WINBASEAPI int WINAPI
LCMapStringW(LCID Locale, DWORD dwMapFlags, LPCWSTR lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest);

//
//

enum class MultiByteToWideCharFlags : DWORD {
    MB_PRECOMPOSED = 0x00000001,
    MB_COMPOSITE = 0x00000002,
    MB_USEGLYPHCHARS = 0x00000004,
    MB_ERR_INVALID_CHARS = 0x00000008,
};

WINBASEAPI int WINAPI
MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr,
                    int cchWideChar);

//
//

enum class WideCharToMultiByteFlags : DWORD {
    None = 0x00000000,

    WC_COMPOSITECHECK = 0x00000200,
    WC_DISCARDNS = 0x00000010,
    WC_SEPCHARS = 0x00000020,
    WC_DEFAULTCHAR = 0x00000040,
    WC_ERR_INVALID_CHARS = 0x00000080,
};

WINBASEAPI int WINAPI
WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWCH lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr,
                    int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar);

//
//

WINBASEAPI BOOL WINAPI GetStringTypeW(DWORD dwInfoType, LPCWCH lpSrcStr, int cchSrc, LPWORD lpCharType);


}

#endif // _WINAPI_STRINGS_HPP_

