#if !defined(_STUB_HPP_)
#define _STUB_HPP_

namespace Core {

typedef DWORD (* IMAGE_ENTRY_POINT)(void);

void EntryPointCaller(void* stackTop, IMAGE_ENTRY_POINT imageEntryPoint);

}

#endif // _STUB_HPP_

