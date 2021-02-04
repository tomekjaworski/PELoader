#include <climits>
#include <unistd.h> // unlink
#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"

#include "../NLS/NLS.hpp"
#include "../Strings/Strings.hpp"
#include "../../Trace/Trace.hpp"

#include "File.hpp"


namespace Core::WinAPI::File {

using namespace Core::WinAPI::Strings;
using namespace Core::WinAPI::NLS;

/// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-deletefilew

WINAPI BOOL DeleteFileW(
    LPCWSTR lpFileName
) {
    USE1(lpFileName);
    TRACEA("lpFileName=%p", lpFileName);

    char fname[PATH_MAX + 1]; //todo: wzięte z climits; poprawić
    WideCharToMultiByte(GetACP(),
                        static_cast<DWORD>(WideCharToMultiByteFlags::None),
                        lpFileName, -1, fname, sizeof(fname), NULL, NULL);
    int status = unlink(fname);
    if (status == 0)
        RETURN_WITH_ERROR(TRUE, ErrorCode::ERROR_SUCCESS);

    if (errno == EACCES)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_ACCESS_DENIED);
    if (errno == ENOENT)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_FILE_NOT_FOUND);
    if (errno == ENOMEM)
        RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_NOT_ENOUGH_MEMORY);

    TRACE_NOT_IMPLEMENTED;
    RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_CALL_NOT_IMPLEMENTED);
}


}


