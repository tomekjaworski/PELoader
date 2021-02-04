#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "ProcessThread.hpp"

namespace Core::WinAPI::ProcessThread {

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-isprocessorfeaturepresent

WINBASEAPI BOOL WINAPI
IsProcessorFeaturePresent(
    DWORD ProcessorFeature
) {
    USE1(ProcessorFeature);
    TRACEA("ProcessorFeature=%u", ProcessorFeature);

    TRACE_NOT_IMPLEMENTED;
    return FALSE;
}

}


