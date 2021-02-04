#include <pthread.h>
#include <algorithm>
#include <cassert>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../InternalHelpers.hpp"
#include "../../Globals.hpp"
#include "../../Trace/Trace.hpp"

#include "Synchronization.hpp"
#include "Structures.hpp"

namespace Globals = Core::Globals;
namespace Core::WinAPI::Synchronization {


/// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-entercriticalsection

WINBASEAPI VOID WINAPI
EnterCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
) {
    USE1(lpCriticalSection);
    TRACEA("lpCriticalSection=%p", (void*)lpCriticalSection);

    pthread_mutex_lock(lpCriticalSection->mutex);
    Globals::last_error_code = ErrorCode::NO_ERROR;
}


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection

WINBASEAPI VOID WINAPI
LeaveCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
) {
    USE1(lpCriticalSection);
    TRACEA("lpCriticalSection=%p", (void*)lpCriticalSection);

    pthread_mutex_unlock(lpCriticalSection->mutex);
    Globals::last_error_code = ErrorCode::NO_ERROR;
}


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection

WINBASEAPI VOID WINAPI
DeleteCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
) {
    TRACEA("lpCriticalSection=%p", (void*)lpCriticalSection);

    free(lpCriticalSection->mutex);
    Globals::last_error_code = ErrorCode::NO_ERROR;
}



//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount

WINBASEAPI BOOL WINAPI
InitializeCriticalSectionAndSpinCount(
    LPCRITICAL_SECTION lpCriticalSection,
    DWORD dwSpinCount
) {
    USE2(lpCriticalSection, dwSpinCount);
    TRACEA("lpCriticalSection=%p, dwSpinCount=%u", (void*)lpCriticalSection, dwSpinCount);

    lpCriticalSection->mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    if (lpCriticalSection->mutex == nullptr)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_NOT_ENOUGH_MEMORY);

    pthread_mutexattr_t attrs;
    pthread_mutexattr_init(&attrs);
    pthread_mutexattr_settype(&attrs, PTHREAD_MUTEX_RECURSIVE);
    int result = pthread_mutex_init(lpCriticalSection->mutex, &attrs);
    assert(result == 0);

    // todo: dwSpinCount
    RETURN_WITH_ERROR(TRUE, ErrorCode::NO_ERROR);
}


}