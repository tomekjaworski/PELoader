#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../BasicDefinitions.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "File.hpp"

namespace Core::WinAPI::File {


/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew
WINBASEAPI HANDLE WINAPI
CreateFileW(
    LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
) {
    USE7(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes,
         hTemplateFile);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return INVALID_HANDLE_VALUE;
}


}


