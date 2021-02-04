#if !defined(__CORE_LOADER_TIB_HPP_)
#define __CORE_LOADER_TIB_HPP_

namespace Core::Loader::Structures {

/// https://en.wikipedia.org/wiki/Win32_Thread_Information_Block
/// https://www.codeproject.com/Articles/2398/Thread-Debugging-with-the-Thread-Information-Block

struct THREAD_INFORMATION_BLOCK {
    PVOID* __reserved0;
    PVOID stack_base;
    PVOID stack_limit;
};


#if defined(CPU32)
static_assert(sizeof(THREAD_INFORMATION_BLOCK) == 12);
#elif defined(CPU64)
static_assert(sizeof(THREAD_INFORMATION_BLOCK) == 24);
#else
#error ?
#endif



}

#endif // __CORE_LOADER_TIB_HPP_


