#if !defined(_WINAPI_PROCESS_ENVIRONMENT_HPP_)
#define _WINAPI_PROCESS_ENVIRONMENT_HPP_

namespace Core::WinAPI::ProcessEnv {

WINBASEAPI LPSTR WINAPI GetCommandLineA(VOID);

WINBASEAPI LPWSTR WINAPI GetCommandLineW(VOID
);

//
//

WINBASEAPI LPWCH WINAPI GetEnvironmentStringsW(VOID);

WINBASEAPI BOOL WINAPI FreeEnvironmentStringsW(LPWCH penv);

//
//

WINBASEAPI BOOL WINAPI SetEnvironmentVariableW(LPCWSTR lpName, LPCWSTR lpValue);

}

#endif // _WINAPI_PROCESS_ENVIRONMENT_HPP_

