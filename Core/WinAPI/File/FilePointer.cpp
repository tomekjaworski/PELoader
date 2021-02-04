#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../BasicMacros.hpp"
#include "../../Trace/Trace.hpp"

#include "File.hpp"

namespace Core::WinAPI::File {



//
// ######################################################
//


/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfilepointerex

WINBASEAPI BOOL WINAPI
SetFilePointerEx(
    HANDLE hFile,
    LARGE_INTEGER liDistanceToMove,
    PLARGE_INTEGER lpNewFilePointer,
    DWORD dwMoveMethod
) {
    USE4(hFile, liDistanceToMove, lpNewFilePointer, dwMoveMethod);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


