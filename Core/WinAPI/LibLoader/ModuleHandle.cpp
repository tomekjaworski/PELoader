#include <stdio.h>

#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "LibLoader.hpp"

namespace Core::WinAPI::LibLoader {



/// https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew

WINBASEAPI HMODULE WINAPI
GetModuleHandleW(
    LPCWSTR lpModuleName
) {
    USE1(lpModuleName);
    TRACEA("lpModuleName=%p", (void*)lpModuleName);

    TRACE_NOT_IMPLEMENTED;
    return NULL;
}


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandleexw

WINBASEAPI BOOL WINAPI
GetModuleHandleExW(
    DWORD dwFlags,
    LPCWSTR lpModuleName,
    HMODULE* phModule
) {
    USE3(dwFlags, lpModuleName, phModule);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


