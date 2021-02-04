#if !defined(_WINAPI_FILE_HPP_)
#define _WINAPI_FILE_HPP_

namespace Core::WinAPI::File {

FORWARD_POINTER(LPSECURITY_ATTRIBUTES)
FORWARD_POINTER(LPOVERLAPPED)
FORWARD_POINTER(LPWIN32_FIND_DATAW)

//
//

WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
                                     LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
                                     DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);

//
//

WINAPI BOOL ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead,
                     LPOVERLAPPED lpOverlapped);

//
//

WINBASEAPI BOOL WINAPI
WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten,
          LPOVERLAPPED lpOverlapped
);

//
//

WINBASEAPI BOOL WINAPI
SetFilePointerEx(HANDLE hFile, LARGE_INTEGER liDistanceToMove, PLARGE_INTEGER lpNewFilePointer, DWORD dwMoveMethod);

WINBASEAPI BOOL WINAPI GetFileSizeEx(HANDLE hFile, PLARGE_INTEGER lpFileSize);
//
//
WINAPI BOOL DeleteFileW(LPCWSTR lpFileName);

//
//

typedef enum _FINDEX_INFO_LEVELS {
    FindExInfoStandard,
    FindExInfoBasic,
    FindExInfoMaxInfoLevel
} FINDEX_INFO_LEVELS;

typedef enum _FINDEX_SEARCH_OPS {
    FindExSearchNameMatch,
    FindExSearchLimitToDirectories,
    FindExSearchLimitToDevices,
    FindExSearchMaxSearchOp
} FINDEX_SEARCH_OPS;

WINBASEAPI HANDLE WINAPI FindFirstFileExW(LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData,
                                          FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags
);

WINBASEAPI BOOL WINAPI FindNextFileW(HANDLE hFindFile, LPWIN32_FIND_DATAW lpFindFileData);

WINBASEAPI BOOL WINAPI FindClose(HANDLE hFindFile);

//
//

WINBASEAPI BOOL WINAPI FlushFileBuffers(HANDLE hFile);

WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);


}

#endif // _WINAPI_FILE_HPP_

