#if !defined(_WINAPI_PROCESTHREAD_HPP_)
#define _WINAPI_PROCESTHREAD_HPP_

namespace Core::WinAPI::ProcessThread {


typedef struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOA, * LPSTARTUPINFOA;

typedef struct _STARTUPINFOW {
    DWORD cb;
    LPCWSTR lpReserved;
    LPCWSTR lpDesktop;
    LPCWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOW, * LPSTARTUPINFOW;

#if defined(CPU64)
static_assert(sizeof(STARTUPINFOW) == 104);
static_assert(sizeof(STARTUPINFOA) == 104);
#else // CPU32
static_assert(sizeof(STARTUPINFOW) == 68);
static_assert(sizeof(STARTUPINFOA) == 68);
#endif


//
//

WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);

//
//

WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);

WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);

WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
//
//

WINBASEAPI BOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

//
//

WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT uExitCode);

WINBASEAPI BOOL WINAPI TerminateProcess(HANDLE hProcess, UINT uExitCode);
//
//

WINBASEAPI DWORD WINAPI TlsAlloc(VOID);

WINBASEAPI LPVOID WINAPI TlsGetValue(DWORD dwTlsIndex);

WINBASEAPI BOOL WINAPI TlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue);

WINBASEAPI BOOL WINAPI TlsFree(DWORD dwTlsIndex);

//
//

}

#endif // _WINAPI_PROCESTHREAD_HPP_

