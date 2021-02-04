#if !defined(_WINAPI_NLS_HPP_)
#define _WINAPI_NLS_HPP_

namespace Core::WinAPI::NLS {


WINBASEAPI BOOL WINAPI IsValidCodePage(UINT CodePage);

//
//

WINBASEAPI UINT WINAPI GetACP(VOID);

WINBASEAPI UINT WINAPI GetOEMCP(void);

//
//

#define MAX_LEADBYTES             12          // 5 ranges, 2 bytes ea., 0 term.
#define MAX_DEFAULTCHAR           2           // single or double byte

typedef struct _cpinfo {
    UINT MaxCharSize;                    // max length (in bytes) of a char
    BYTE DefaultChar[MAX_DEFAULTCHAR];   // default character
    BYTE LeadByte[MAX_LEADBYTES];        // lead byte ranges
} CPINFO, * LPCPINFO;


WINBASEAPI BOOL WINAPI GetCPInfo(UINT CodePage, LPCPINFO lpCPInfo);


}

#endif // _WINAPI_NLS_HPP_

