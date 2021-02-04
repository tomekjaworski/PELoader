#include <stdio.h>
#include <assert.h>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "File.hpp"

namespace Core::WinAPI::File {

/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-writefile

WINBASEAPI BOOL WINAPI
WriteFile(
    HANDLE hFile,
    LPCVOID lpBuffer,
    DWORD nNumberOfBytesToWrite,
    LPDWORD lpNumberOfBytesWritten,
    LPOVERLAPPED lpOverlapped
) {
    USE5(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
    TRACE();

    if (lpBuffer == NULL)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_PARAMETER);

    // todo Overlaped
    assert(lpOverlapped == nullptr);

    FILE* f = reinterpret_cast<FILE*>(hFile);
    if (f != stdout && f != stderr)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_INVALID_HANDLE);

    size_t written = fwrite(lpBuffer, 1, nNumberOfBytesToWrite, f);
    if (lpNumberOfBytesWritten != NULL)
        *lpNumberOfBytesWritten = static_cast<DWORD>(written);

    // autoflush
    fflush(f);

    if (written < nNumberOfBytesToWrite) {
        int err = errno;
        if (err == 0)
            RETURN_WITH_ERROR(TRUE, ErrorCode::ERROR_SUCCESS);

        // todo: tymczasowa odpowiedź:
        RETURN_WITH_ERROR(TRUE, ErrorCode::ERROR_NOT_READY);
    }

    RETURN_WITH_ERROR(TRUE, ErrorCode::ERROR_SUCCESS);
}


}


