#include <string.h>
#include <assert.h>
#include <malloc.h>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../BasicDefinitions.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Helpers/Helper.hpp"
#include "../../Trace/Trace.hpp"

#include "Heap.hpp"


namespace Core::WinAPI::Heap {


enum class HeapFlags : DWORD {
    HEAP_NONE = 0x00000000,
    HEAP_ZERO_MEMORY = 0x00000008,
};


/// https://docs.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapalloc

WINBASEAPI  DECLSPEC_ALLOCATOR LPVOID WINAPI
HeapAlloc(
    HANDLE hHeap,
    DWORD dwFlags,
    SIZE_T dwBytes
) {
    USE3(hHeap, dwFlags, dwBytes);
    TRACEA("hHeap=%p, dwFlags=%08x, dwBytes=%llu", (void*)hHeap, dwFlags, dwBytes);

    HeapFlags flags = static_cast<HeapFlags>(dwFlags);

    if (hHeap != DEFAULT_HEAP)
        assert(false); // no właśnie, co wtedy?

    void* ptr = malloc(dwBytes);
    if (ptr == NULL)
        RETURN_WITH_ERROR(NULL, ErrorCode::ERROR_NOT_ENOUGH_MEMORY);

    assert(flags == HeapFlags::HEAP_ZERO_MEMORY ||
           flags == HeapFlags::HEAP_NONE); // DEBUG

    if (IsFlagSet<HeapFlags::HEAP_ZERO_MEMORY>(flags))
        memset(ptr, 0, dwBytes);

    RETURN_WITH_ERROR(ptr, ErrorCode::NO_ERROR);
}

//
// ######################################################
//



WINBASEAPI  DECLSPEC_ALLOCATOR LPVOID WINAPI
HeapReAlloc(
    HANDLE hHeap,
    DWORD dwFlags,
    LPVOID lpMem,
    SIZE_T dwBytes
) {
    USE4(hHeap, dwFlags, lpMem, dwBytes);
    TRACEA("hHeap=%p, dwFlags=%08x, lpMem=%p, dwBytes=%llu", (void*)hHeap, dwFlags, (void*)lpMem, dwBytes);

    if (hHeap != DEFAULT_HEAP)
        assert(false); // no właśnie, co wtedy?

    TRACE_NOT_IMPLEMENTED;
    return NULL;
}

//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapfree

WINBASEAPI BOOL WINAPI
HeapFree(
    HANDLE hHeap,
    DWORD dwFlags,
    LPVOID lpMem
) {
    USE3(hHeap, dwFlags, lpMem);
    TRACEA("hHeap=%p, dwFlags=%08x, lpMem=%p", (void*)hHeap, dwFlags, (void*)lpMem);

    if (hHeap != DEFAULT_HEAP)
        assert(false); // no właśnie, co wtedy?

    if (lpMem == NULL)
        RETURN_WITH_ERROR(TRUE, ErrorCode::NO_ERROR);

    free(lpMem);
    RETURN_WITH_ERROR(TRUE, ErrorCode::NO_ERROR);

    return FALSE;
}

//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapsize

WINBASEAPI SIZE_T WINAPI
HeapSize(
    HANDLE hHeap,
    DWORD dwFlags,
    LPCVOID lpMem
) {
    USE3(hHeap, dwFlags, lpMem);
    TRACEA("hHeap=%p, dwFlags=%08x, lpMem=%p", (void*)hHeap, dwFlags, (void*)lpMem);

    if (hHeap != DEFAULT_HEAP)
        assert(false); // no właśnie, co wtedy?

    if (lpMem == NULL)
        return (SIZE_T)-1; // funkcja nie wywołuje SetLastError

    size_t size = malloc_usable_size(const_cast<void*>(lpMem)); //todo: funkcja NIE JEST standardowa
    return size;
}


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-getprocessheap

WINBASEAPI HANDLE WINAPI
GetProcessHeap(
    VOID
) {
    TRACE();
    RETURN_WITH_ERROR(DEFAULT_HEAP, ErrorCode::NO_ERROR);
}


}


