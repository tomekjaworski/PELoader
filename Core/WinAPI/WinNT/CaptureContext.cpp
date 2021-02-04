#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"


#include "WinNT.hpp"

namespace Core::WinAPI::WinNT {

NTSYSAPI VOID NTAPI
RtlCaptureContext(
    PCONTEXT ContextRecord
) {
    USE1(ContextRecord);
    TRACEA("ContextRecord=%p", (void*)ContextRecord);

    TRACE_NOT_IMPLEMENTED;
    return;
}


}


