#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "LibLoader.hpp"

namespace Core::WinAPI::LibLoader {


//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary

WINBASEAPI BOOL WINAPI
FreeLibrary(
    HMODULE hLibModule
) {
    USE1(hLibModule);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


