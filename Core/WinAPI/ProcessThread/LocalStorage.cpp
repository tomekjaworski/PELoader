#include <unordered_map>
#include <vector>
#include <mutex>
#include <unistd.h>
#include <sys/syscall.h>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "ProcessThread.hpp"


#define TLS_OUT_OF_INDEXES ((DWORD)0xFFFFFFFF)

namespace Core::WinAPI::ProcessThread {

//todo: potrzebny benchmark
std::vector<std::unordered_map<pid_t, LPVOID>> tls_slots = {{ }};
std::mutex tls_sync;

/// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc

WINBASEAPI DWORD WINAPI
TlsAlloc(
    VOID
) {
    TRACE();

    {
        std::lock_guard guard(tls_sync);
        if (tls_slots.size() > 1024) // jakiś przyjęty limit
            RETURN_WITH_ERROR(TLS_OUT_OF_INDEXES, ErrorCode::ERROR_NOT_ENOUGH_MEMORY);

        DWORD index = tls_slots.size();
        tls_slots.push_back({ });
        pid_t current_tid = syscall(__NR_gettid);
        tls_slots[index][current_tid] = (LPVOID)nullptr;
        RETURN_WITH_ERROR(index, ErrorCode::NO_ERROR);
    }
}

//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue
WINBASEAPI LPVOID WINAPI
TlsGetValue(
    DWORD dwTlsIndex
) {
    USE1(dwTlsIndex);

    TRACE();

    pid_t current_tid = syscall(__NR_gettid);
    {
        std::lock_guard guard(tls_sync);
        if (dwTlsIndex >= tls_slots.

            size()

            )
            RETURN_WITH_ERROR(NULL, ErrorCode::ERROR_INVALID_INDEX);

        auto& dict = tls_slots[dwTlsIndex];
        const auto it = dict.find(current_tid);
        if (it == dict.

            end()

            )
            RETURN_WITH_ERROR(NULL, ErrorCode::NO_ERROR);
        else
            RETURN_WITH_ERROR(it->second, ErrorCode::NO_ERROR);
    }
}

//
// ######################################################
//



WINBASEAPI BOOL WINAPI
TlsSetValue(
    DWORD dwTlsIndex,
    LPVOID lpTlsValue
) {
    USE2(dwTlsIndex, lpTlsValue);
    TRACE();

    pid_t current_tid = syscall(__NR_gettid);

    {
        std::lock_guard guard(tls_sync);
        if (dwTlsIndex >= tls_slots.size())
            RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_INDEX);

        auto& dict = tls_slots[dwTlsIndex];
        dict[current_tid] = lpTlsValue;
        RETURN_WITH_ERROR(TRUE, ErrorCode::NO_ERROR);
    }
}


//
// ######################################################
//


WINBASEAPI BOOL WINAPI
TlsFree(
    DWORD dwTlsIndex
) {
    USE1(dwTlsIndex);
    TRACE();

    //WINAPI_NOT_IMPLEMENTED(NULL);
    //return FALSE;
    RETURN_WITH_ERROR(TRUE, ErrorCode::NO_ERROR);
}


}


