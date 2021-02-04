#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../BasicMacros.hpp"
#include "../../Trace/Trace.hpp"

#include "File.hpp"

namespace Core::WinAPI::File {

/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfilesizeex

WINBASEAPI BOOL WINAPI
GetFileSizeEx(
    HANDLE hFile,
    PLARGE_INTEGER lpFileSize
) {
    USE2(hFile, lpFileSize);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


