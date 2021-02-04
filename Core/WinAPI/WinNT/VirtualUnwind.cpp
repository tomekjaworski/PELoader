#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "WinNT.hpp"

namespace Core::WinAPI::WinNT {

/// https://docs.microsoft.com/en-us/windows/win32/api/winnt/nf-winnt-rtlvirtualunwind

NTSYSAPI PEXCEPTION_ROUTINE NTAPI
RtlVirtualUnwind(
    DWORD HandlerType,
    DWORD64 ImageBase,
    DWORD64 ControlPc,
    PRUNTIME_FUNCTION FunctionEntry,
    PCONTEXT ContextRecord,
    PVOID* HandlerData,
    PDWORD64 EstablisherFrame,
    PKNONVOLATILE_CONTEXT_POINTERS ContextPointers
) {
    USE8(HandlerType, ImageBase, ControlPc, FunctionEntry, ContextRecord, HandlerData, EstablisherFrame,
         ContextPointers);
    TRACEA(
        "HandlerType=%u, ImageBase=%x, ControlPc=%x, FunctionEntry=%p, ContextRecord=%p, HandlerData=%p, EstablisherFrame=%p, ContextPointers=%p",
        HandlerType, ImageBase, ControlPc, FunctionEntry, ContextRecord, (void*)HandlerData,
        (void*)EstablisherFrame,
        (void*)ContextPointers);

    TRACE_NOT_IMPLEMENTED;
    return NULL;
}

}