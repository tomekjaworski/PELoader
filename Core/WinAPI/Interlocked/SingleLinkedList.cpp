#include <cstring>

#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "Interlocked.hpp"

namespace Core::WinAPI::Interlocked {


//
//
//

/// https://docs.microsoft.com/en-us/windows/win32/api/interlockedapi/nf-interlockedapi-initializeslisthead

WINBASEAPI VOID WINAPI
InitializeSListHead(
    PSLIST_HEADER ListHead
) {
    USE1(ListHead);
    TRACEA("ListHead=%p", (void*)ListHead);

    memset(ListHead, 0x00, sizeof(SLIST_HEADER));
    return;
}


}


