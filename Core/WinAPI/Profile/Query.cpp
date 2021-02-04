#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "Profile.hpp"


namespace Core::WinAPI::Profile {

//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter

WINBASEAPI BOOL WINAPI
QueryPerformanceCounter(
    LARGE_INTEGER* lpPerformanceCount
) {
    USE1(lpPerformanceCount);
    TRACEA("lpPerformanceCount=%p", (void*)lpPerformanceCount);

    if (lpPerformanceCount == nullptr)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    timespec ts;
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    int64_t counter = ts.tv_sec * 1e9 + ts.tv_nsec;
    lpPerformanceCount->QuadPart = static_cast<LONGLONG>(counter);
    return TRUE;
}

}