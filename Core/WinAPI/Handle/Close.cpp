#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "Handle.hpp"

namespace Core::WinAPI::Handle {



/// https://docs.microsoft.com/en-us/windows/win32/api/handleapi/nf-handleapi-closehandle

WINBASEAPI BOOL WINAPI
CloseHandle(
    HANDLE hObject
) {
    USE1(hObject);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}


}


