#if !defined(_WINAPI_UTILS_HPP_)
#define _WINAPI_UTILS_HPP_

namespace Core::WinAPI::Util {

WINBASEAPI PVOID WINAPI DecodePointer(PVOID Ptr);

WINBASEAPI PVOID WINAPI EncodePointer(PVOID Ptr);

}

#endif // _WINAPI_UTILS_HPP_

