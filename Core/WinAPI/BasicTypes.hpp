#if !defined (_WINAPI_COMMON_HPP_)
#define _WINAPI_COMMON_HPP_

#include <bits/wordsize.h>
#include <cstdint>


#if __WORDSIZE == 32
#define CPU32
#elif  __WORDSIZE == 64
#define CPU64
#else
#error ?
#endif


#define WINBASEAPI
#define DECLSPEC_ALLOCATOR

#define far
#define near
#define FAR

#define NTSYSAPI
#define DECLSPEC_NOINITALL
#define DECLSPEC_NORETURN // __attribute__ ((noreturn))
#define DECLSPEC_ALIGN(x)   __attribute__((aligned (x)))


#if defined(CPU32)
#define WINAPI __attribute__((stdcall))
#define NTAPI __attribute__((stdcall))
#else
#define WINAPI __attribute__((ms_abi))
#define NTAPI __attribute__((ms_abi))
#endif

// --------- FROM winnt.h -------------

#define CONST const

#define VOID void
typedef char                CHAR;
typedef short               SHORT;
typedef int                 LONG;
typedef unsigned            ULONG;

typedef unsigned int        DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef FLOAT               *PFLOAT;
typedef BOOL near           *PBOOL;
typedef BOOL far            *LPBOOL;
typedef BYTE near           *PBYTE;
typedef BYTE far            *LPBYTE;
typedef int near            *PINT;
typedef int far             *LPINT;
typedef WORD near           *PWORD;
typedef WORD far            *LPWORD;
typedef long far            *LPLONG;
typedef DWORD near          *PDWORD;
typedef DWORD far           *LPDWORD;
typedef void far            *LPVOID;
typedef CONST void far      *LPCVOID;

typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;

typedef void                *PVOID;
typedef PVOID               HANDLE;
typedef PVOID               HINSTANCE;
typedef PVOID               HMODULE;

typedef void far            *LPVOID;

typedef int64_t             LONGLONG;
typedef uint64_t            ULONGLONG;


typedef uint64_t            ULONG64, *PULONG64;
typedef uint64_t            DWORD64, *PDWORD64;


typedef intptr_t            INT_PTR, *PINT_PTR;
typedef uintptr_t           UINT_PTR, *PUINT_PTR;

typedef intptr_t            LONG_PTR, *PLONG_PTR;
typedef uintptr_t           ULONG_PTR, *PULONG_PTR;

typedef ULONG_PTR           SIZE_T, *PSIZE_T;
typedef LONG_PTR            SSIZE_T, *PSSIZE_T;


typedef DWORD               LCID;


//
// ANSI (Multi-byte Character) types
//
typedef CONST CHAR          *LPCCH, *PCCH;

typedef  CHAR               *NPSTR, *LPSTR, *PSTR;
typedef  PSTR               *PZPSTR;
typedef  CONST CHAR         *LPCSTR, *PCSTR;

typedef  CHAR               *PNZCH;
typedef  CONST CHAR         *PCNZCH;

// -------------------


//
// UNICODE (Wide Character) types
//

typedef char16_t WCHAR;    // wc,   16-bit UNICODE character
static_assert(sizeof(WCHAR) == 2);

typedef WCHAR *PWCHAR, *LPWCH, *PWCH;
typedef CONST WCHAR *LPCWCH, *PCWCH;

typedef  WCHAR *NWPSTR, *LPWSTR, *PWSTR;
//typedef  PWSTR *PZPWSTR;
//typedef  CONST PWSTR *PCZPWSTR;
//typedef  WCHAR UNALIGNED *LPUWSTR, *PUWSTR;
typedef  CONST WCHAR *LPCWSTR, *PCWSTR;
//typedef  PCWSTR *PZPCWSTR;
//typedef  CONST PCWSTR *PCZPCWSTR;
//typedef  CONST WCHAR UNALIGNED *LPCUWSTR, *PCUWSTR;

//typedef  WCHAR *PZZWSTR;
//typedef  CONST WCHAR *PCZZWSTR;
//typedef  WCHAR UNALIGNED *PUZZWSTR;
//typedef  CONST WCHAR UNALIGNED *PCUZZWSTR;

//typedef  WCHAR *PNZWCH;
typedef  CONST WCHAR *PCNZWCH;
//typedef  WCHAR UNALIGNED *PUNZWCH;
//typedef  CONST WCHAR UNALIGNED *PCUNZWCH;

typedef CONST WCHAR *LPCWCHAR, *PCWCHAR;
//typedef CONST WCHAR UNALIGNED *LPCUWCHAR, *PCUWCHAR;

// -------------------

typedef INT_PTR (FAR WINAPI *FARPROC)();


// -------------------

#undef TRUE
#undef FALSE
#define FALSE               0
#define TRUE                1

// --------------------

static_assert(sizeof(BYTE) == 1);
static_assert(sizeof(CHAR) == 1);

static_assert(sizeof(WORD) == 2);
static_assert(sizeof(SHORT) == 2);
static_assert(sizeof(WCHAR) == 2);

static_assert(sizeof(INT) == 4);
static_assert(sizeof(UINT) == 4);

static_assert(sizeof(LONG) == 4);
static_assert(sizeof(ULONG) == 4);

static_assert(sizeof(DWORD) == 4);
static_assert(sizeof(BOOL) == 4);
static_assert(sizeof(FLOAT) == 4);

static_assert(sizeof(LONG_PTR) == sizeof(void*));
static_assert(sizeof(ULONG_PTR) == sizeof(void*));

static_assert(sizeof(SIZE_T) == sizeof(void*));
static_assert(sizeof(SSIZE_T) == sizeof(void*));

static_assert(sizeof(LONGLONG) == 8);
static_assert(sizeof(ULONGLONG) == 8);

static_assert(sizeof(HANDLE) == sizeof(void*));
static_assert(sizeof(HMODULE) == sizeof(void*));
static_assert(sizeof(HINSTANCE) == sizeof(void*));

static_assert(sizeof(INT_PTR) == sizeof(void*));
static_assert(sizeof(UINT_PTR) == sizeof(void*));

static_assert(sizeof(FARPROC) == sizeof(void*));

static_assert(sizeof(uintptr_t) == sizeof(void*));


// -----------------

typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    } DUMMYSTRUCTNAME;
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    LONGLONG QuadPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

static_assert(sizeof(LARGE_INTEGER) == 8);

#endif // _WINAPI_COMMON_HPP_
