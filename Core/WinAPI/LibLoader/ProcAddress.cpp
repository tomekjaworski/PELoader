#include <stdio.h>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "LibLoader.hpp"

namespace Core::WinAPI::LibLoader {



/// https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress

WINBASEAPI FARPROC WINAPI
GetProcAddress(
    HMODULE hModule,
    LPCSTR lpProcName
) {
    USE2(hModule, lpProcName);
    TRACEA("hModule=%p, lpProcName=%s", (void*)hModule, lpProcName);


    RETURN_WITH_ERROR(NULL, ErrorCode::ERROR_PROC_NOT_FOUND);
}

//
// ######################################################
//



}


