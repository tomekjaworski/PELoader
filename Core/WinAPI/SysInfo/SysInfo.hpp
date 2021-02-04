#if !defined(_WINAPI_SYSINFO_HPP_)
#define _WINAPI_SYSINFO_HPP_

namespace Core::WinAPI::SysInfo {

typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, * PFILETIME, * LPFILETIME;

//
//

WINBASEAPI VOID WINAPI GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime);

}

#endif // _WINAPI_SYSINFO_HPP_

