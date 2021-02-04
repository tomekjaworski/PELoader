#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../BasicMacros.hpp"
#include "../../Trace/Trace.hpp"

#include "File.hpp"

namespace Core::WinAPI::File {



/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-flushfilebuffers

WINBASEAPI BOOL WINAPI
FlushFileBuffers(
    HANDLE hFile
) {
    USE1(hFile);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


