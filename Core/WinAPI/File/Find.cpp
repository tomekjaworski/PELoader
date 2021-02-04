#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../BasicDefinitions.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "File.hpp"

namespace Core::WinAPI::File {

/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfileexw
WINBASEAPI HANDLE WINAPI
FindFirstFileExW(
    LPCWSTR lpFileName,
    FINDEX_INFO_LEVELS fInfoLevelId,
    LPVOID lpFindFileData,
    FINDEX_SEARCH_OPS fSearchOp,
    LPVOID lpSearchFilter,
    DWORD dwAdditionalFlags
) {
    USE6(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return INVALID_HANDLE_VALUE;
}


//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findnextfilew
WINBASEAPI BOOL  WINAPI
FindNextFileW(
    HANDLE hFindFile,
    LPWIN32_FIND_DATAW lpFindFileData
) {
    USE2(hFindFile, lpFindFileData);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}



//
// ######################################################
//



WINBASEAPI BOOL WINAPI
FindClose(
    HANDLE hFindFile
) {
    USE1(hFindFile);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


