#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "WinNT.hpp"

namespace Core::WinAPI::WinNT {

/// https://docs.microsoft.com/en-us/windows/win32/api/winnt/nf-winnt-rtllookupfunctionentry

NTSYSAPI PRUNTIME_FUNCTION NTAPI
RtlLookupFunctionEntry(
    DWORD64 ControlPc,
    PDWORD64 ImageBase,
    PUNWIND_HISTORY_TABLE HistoryTable
) {
    USE3(ControlPc, ImageBase, HistoryTable);
    TRACEA("ControlPc=%llu, ImageBase=%p, HistoryTable=%p", ControlPc, (void*)ImageBase, HistoryTable);

    TRACE_NOT_IMPLEMENTED;
    return NULL;
}

}
