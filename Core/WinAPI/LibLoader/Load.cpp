#include <stdio.h>
#include <climits>
#include <stdlib.h>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "LibLoader.hpp"

namespace Core::WinAPI::LibLoader {

/// https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw

enum class LoadLibraryFlags : DWORD {
    DONT_RESOLVE_DLL_REFERENCES = 0x00000001,
    LOAD_LIBRARY_AS_DATAFILE = 0x00000002,
    LOAD_WITH_ALTERED_SEARCH_PATH = 0x00000008,
    LOAD_IGNORE_CODE_AUTHZ_LEVEL = 0x00000010,
    LOAD_LIBRARY_AS_IMAGE_RESOURCE = 0x00000020,
    LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE = 0x00000040,
    LOAD_LIBRARY_REQUIRE_SIGNED_TARGET = 0x00000080,
    LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR = 0x00000100,
    LOAD_LIBRARY_SEARCH_APPLICATION_DIR = 0x00000200,
    LOAD_LIBRARY_SEARCH_USER_DIRS = 0x00000400,
    LOAD_LIBRARY_SEARCH_SYSTEM32 = 0x00000800,
    LOAD_LIBRARY_SEARCH_DEFAULT_DIRS = 0x00001000,
};


int naive_wchar_to_multibyte(char* dest, int size, LPCWSTR source) {
    if (source == NULL)
        return -1;

    LPCWSTR pstart = source;
    if (dest == NULL || size <= 0) {
        for (; *source; source++);
        return source - pstart;
    } else {
        size--; // uwzględnij miejsce na terminator
        for (; *source && size > 0; source++, dest++, size--)
            *dest = (char)*source; // todo: obsługa lokalizacji (!!)
        *dest = '\x0';
        return source - pstart;
    }
}

/// https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw
WINBASEAPI HMODULE WINAPI
LoadLibraryExW(
    LPCWSTR lpLibFileName,
    HANDLE hFile,
    DWORD dwFlags
) {
    USE3(lpLibFileName, hFile, dwFlags);

    LoadLibraryFlags flags = static_cast<LoadLibraryFlags>(dwFlags);
    USE1(flags);

    char libname[PATH_MAX]; //todo: path_max - popawwić
    naive_wchar_to_multibyte(libname, PATH_MAX, reinterpret_cast<LPCWSTR>(lpLibFileName));
    TRACEA("lpLibFileName=%s, hFile=%p, dwFlags=%08x", libname, (void*)hFile, dwFlags);


    RETURN_WITH_ERROR((void*)42, ErrorCode::NO_ERROR);
    //WINAPI_NOT_IMPLEMENTED(NULL);
    //RETURN_WITH_ERROR(FALSE, ErrorCode::ERROR_MOD_NOT_FOUND);
    return FALSE;
}


}


