#include <cassert>
#include <stdio.h>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "File.hpp"

namespace Core::WinAPI::File {


enum class FileTypeType { // takie masło maślane
    FILE_TYPE_CHAR = 0x0002,
    FILE_TYPE_DISK = 0x0001,
    FILE_TYPE_PIPE = 0x0003,
    FILE_TYPE_REMOTE = 0x8000,
    FILE_TYPE_UNKNOWN = 0x0000,
};

/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfiletype

WINBASEAPI DWORD WINAPI
GetFileType(
    HANDLE hFile
) {
    USE1(hFile);
    TRACE();

    FILE* h = reinterpret_cast<FILE*>(hFile);
    if (h == stdin || h == stdout || h == stderr)
        RETURN_WITH_ERROR(
            static_cast<DWORD>(FileTypeType::FILE_TYPE_CHAR),
            ErrorCode::NO_ERROR
        );

    // unknown + success
    // unknown + invalid_handle_value
    assert(false);

    RETURN_WITH_ERROR(
        static_cast<DWORD>(FileTypeType::FILE_TYPE_UNKNOWN),
        ErrorCode::ERROR_INVALID_HANDLE
    );
}


}


