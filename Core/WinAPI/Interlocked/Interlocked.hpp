#if !defined(_WINAPI_INTERLOCKED_HPP_)
#define _WINAPI_INTERLOCKED_HPP_

namespace Core::WinAPI::Interlocked {

#if defined(CPU64)

typedef struct DECLSPEC_ALIGN(16) _SLIST_ENTRY {
    struct _SLIST_ENTRY *Next;
} SLIST_ENTRY, *PSLIST_ENTRY;

typedef union DECLSPEC_ALIGN(16) _SLIST_HEADER {
struct {  // original struct
    ULONGLONG Alignment;
    ULONGLONG Region;
} DUMMYSTRUCTNAME;

struct {  // x64 16-byte header
    ULONGLONG Depth: 16;
    ULONGLONG Sequence: 48;
    ULONGLONG Reserved: 4;
    ULONGLONG NextEntry: 60; // last 4 bits are always 0's
} HeaderX64;
} SLIST_HEADER,* PSLIST_HEADER;

// ---

static_assert(sizeof(SLIST_HEADER) == 16);
static_assert(sizeof(SLIST_ENTRY) == 16);

#elif defined(CPU32)


typedef struct _SINGLE_LIST_ENTRY {
    struct _SINGLE_LIST_ENTRY* Next;
} SINGLE_LIST_ENTRY, * PSINGLE_LIST_ENTRY;


typedef struct _SINGLE_LIST_ENTRY SLIST_ENTRY, * PSLIST_ENTRY;

typedef union _SLIST_HEADER {
    ULONGLONG Alignment;
    struct {
        SLIST_ENTRY Next;
        WORD Depth;
        WORD CpuId;
    } DUMMYSTRUCTNAME;
} SLIST_HEADER, * PSLIST_HEADER;

// ---

static_assert(sizeof(SLIST_HEADER) == 8); // aby na pewno?
static_assert(sizeof(SLIST_ENTRY) == 4); // aby na pewno?

#endif // CPU32

//
//

WINBASEAPI VOID WINAPI InitializeSListHead(PSLIST_HEADER ListHead);


}

#endif // _WINAPI_INTERLOCKED_HPP_

