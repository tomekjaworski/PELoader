#if !defined(_CONSOLE_HPP_)
#define _CONSOLE_HPP_

namespace Core::WinAPI::Console {

WINBASEAPI BOOL WINAPI
WriteConsoleW(HANDLE hConsoleOutput, CONST VOID* lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten,
              LPVOID lpReserved);

WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);

WINBASEAPI BOOL WINAPI SetStdHandle(DWORD nStdHandle, HANDLE hHandle);

WINBASEAPI UINT WINAPI GetConsoleCP(VOID);

WINBASEAPI BOOL WINAPI GetConsoleMode(HANDLE hConsoleHandle, LPDWORD lpMode);

}

#endif // _CONSOLE_HPP_

