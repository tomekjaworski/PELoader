#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "WinNT.hpp"

namespace Core::WinAPI::WinNT {

/// https://docs.microsoft.com/en-us/windows/win32/api/winnt/nf-winnt-rtlunwindex

NTSYSAPI VOID NTAPI
RtlUnwindEx(
    PVOID TargetFrame,
    PVOID TargetIp,
    PEXCEPTION_RECORD ExceptionRecord,
    PVOID ReturnValue,
    PCONTEXT ContextRecord,
    PUNWIND_HISTORY_TABLE HistoryTable
) {
    USE6(TargetFrame, TargetIp, ExceptionRecord, ReturnValue, ContextRecord, HistoryTable);
    TRACEA("TargetFrame=%p, TargetIp=%p, ExceptionRecord=%p, ReturnValue=%p, ContextRecord=%p, HistoryTable=%p",
           (void*)TargetFrame, (void*)TargetIp, (void*)ExceptionRecord, (void*)ReturnValue,
           (void*)ContextRecord, (void*)HistoryTable);

    TRACE_NOT_IMPLEMENTED;
    return;
}


}