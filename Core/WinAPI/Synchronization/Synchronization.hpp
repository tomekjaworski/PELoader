#if !defined(_WINAPI_SYNCHRONIZATION_HPP_)
#define _WINAPI_SYNCHRONIZATION_HPP_

namespace Core::WinAPI::Synchronization {

struct CRITICAL_SECTION;
typedef CRITICAL_SECTION* LPCRITICAL_SECTION;

//
//

WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);

WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds, BOOL bAlertable);

//
//


WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

WINBASEAPI BOOL WINAPI InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount);

}

#endif // _WINAPI_SYNCHRONIZATION_HPP_
