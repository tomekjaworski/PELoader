#if !defined(_WINAPI_PROFILE_HPP_)
#define _WINAPI_PROFILE_HPP_

namespace Core::WinAPI::Profile {

WINBASEAPI BOOL WINAPI QueryPerformanceCounter(PLARGE_INTEGER lpPerformanceCount);

}

#endif // _WINAPI_PROFILE_HPP_

