#if !defined(_PRINTERS_HPP_)
#define _PRINTERS_HPP_

namespace Core::WinAPI::Debug {

WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);

WINBASEAPI VOID WINAPI DebugBreak(VOID);

WINBASEAPI BOOL WINAPI IsDebuggerPresent(VOID);

}

#endif // _PRINTERS_HPP_
