#include <stdio.h>
#include <cassert>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "File.hpp"

namespace Core::WinAPI::File {


/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-readfile

WINAPI BOOL ReadFile(
    HANDLE hFile,
    LPVOID lpBuffer,
    DWORD nNumberOfBytesToRead,
    LPDWORD lpNumberOfBytesRead,
    LPOVERLAPPED lpOverlapped
) {
    USE5(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
    TRACEA("hFile=%p, lpBuffer=%p, nNumberOfBytesToRead=%u, lpNumberOfBytesRead=%p, lpOverlapped=%p",
           hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
    if (lpBuffer == NULL)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    // todo Overlaped
    assert(lpOverlapped == nullptr);

    FILE* f = reinterpret_cast<FILE*>(hFile);
    if (f != stdin)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_HANDLE);

    int bytes_read = fread(lpBuffer, 1, 2, f);
    if (bytes_read == 0) {
        TRACEA("errno=%d", errno);
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_NOT_READY);
    }

    if (lpNumberOfBytesRead != nullptr)
        *lpNumberOfBytesRead = bytes_read;

    RETURN_WITH_ERROR(TRUE, ErrorCode::ERROR_SUCCESS);
}


}


