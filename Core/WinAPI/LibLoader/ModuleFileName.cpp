#include <assert.h>

#include "../BasicTypes.hpp"
#include "../BasicMacros.hpp"
#include "../../Globals.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "../BasicMacros.hpp"
#include "LibLoader.hpp"

namespace Globals = Core::Globals;
namespace Core::WinAPI::LibLoader {

__attribute__((optimize("unroll-loops")))
char16_t* ucs16_strcpy(char16_t* dest, const char16_t* src) {
    do {
        for (int i = 0; i < 8; i++) {
            *dest = *src;
            if (*src == 0) return dest;
            dest++, src++;
        }
    } while (true);
}

/// https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew

WINBASEAPI DWORD WINAPI
GetModuleFileNameW(
    HMODULE hModule,
    LPWSTR lpFilename,
    DWORD nSize
) {
    USE3(hModule, lpFilename, nSize);
    TRACE();

    assert(hModule == nullptr);
    assert(nSize >= Globals::process_control_block.GetWideImageFileName().size()); // todo: ERROR_INSUFFICIENT_BUFFER.

    int chars_to_copy = Globals::process_control_block.GetWideImageFileName().size();
    ucs16_strcpy(lpFilename, Globals::process_control_block.GetWideImageFileName().c_str());

    RETURN_WITH_ERROR(chars_to_copy, ErrorCode::ERROR_SUCCESS);
}


}


