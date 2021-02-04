#include "../BasicTypes.hpp"
#include "../InternalHelpers.hpp"
#include "../../Trace/Trace.hpp"

#include "Strings.hpp"

namespace Core::WinAPI::Strings {


/// https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-comparestringw
/// https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-comparestringex
WINBASEAPI int WINAPI
CompareStringW(
    LCID Locale,
    DWORD dwCmpFlags,
    PCNZWCH lpString1,
    int cchCount1,
    PCNZWCH lpString2,
    int cchCount2
) {
    USE6(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2);
    TRACE();

    TRACE_NOT_IMPLEMENTED;
    return 0;
}


}


