#if !defined(_WINAPI_LIBLOADER_HPP_)
#define _WINAPI_LIBLOADER_HPP_

namespace Core::WinAPI::LibLoader {

WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize);

WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

WINBASEAPI BOOL WINAPI GetModuleHandleExW(DWORD dwFlags, LPCWSTR lpModuleName, HMODULE* phModule);

//
//

WINBASEAPI HMODULE WINAPI LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);

WINBASEAPI FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName);

WINBASEAPI BOOL WINAPI FreeLibrary(HMODULE hLibModule);

}

#endif // _WINAPI_LIBLOADER_HPP_

