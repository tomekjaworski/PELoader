#include "../BasicTypes.hpp"
#include "../../Globals.hpp"
#include "../../Trace/Trace.hpp"


#include "ProcesEnv.hpp"

namespace Globals = Core::Globals;
namespace Core::WinAPI::ProcessEnv {

/// https://docs.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-getcommandlinea

WINBASEAPI LPSTR WINAPI
GetCommandLineA(
    VOID
) {
    TRACE();

    const char* str = Globals::process_control_block.GetAnsiCommandLine().c_str();
    return const_cast<LPSTR>(str);
}

//
// ######################################################
//

/// https://docs.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-getcommandlinew

WINBASEAPI LPWSTR WINAPI
GetCommandLineW(
    VOID
) {
    TRACE();

    const char16_t* str = Globals::process_control_block.GetWideCommandLine().c_str();
    return const_cast<LPWSTR>(str);
}


}


