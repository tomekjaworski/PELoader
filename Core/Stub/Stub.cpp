#include <csetjmp>
#include <cstdint>
#include "../WinAPI/BasicTypes.hpp"
#include "../WinAPI/ProcessThread/ProcessThread.hpp"
#include "../WinAPI/InternalHelpers.hpp"
#include "Stub.hpp"


#define WANT_PROCESS_EXIT_POINT
#include "../Globals.hpp"
#undef WANT_PROCESS_EXIT_POINT



namespace Globals = Core::Globals;
namespace Core {


void EntryPointCaller(void* stackTop, IMAGE_ENTRY_POINT imageEntryPoint) {
    static std::intptr_t old_stack_pointer;
    static std::uint16_t old_fs;
    USE1(old_fs);

#if defined(CPU64)
    asm("push rax");
    asm("mov rax, rsp");
    asm("mov %0, rax":"=r"(old_stack_pointer));
    asm("mov rax, %0"::"a"(stackTop));
    asm("mov rsp, rax");
#elif defined(CPU32)
    asm("push eax");
    asm("mov ax, fs");
    asm("push ax");
    asm("mov %0, ax":"=r"(old_fs));
    asm("mov eax, esp");
    asm("mov %0, eax":"=r"(old_stack_pointer));
    asm("mov eax, %0"::"a"(stackTop));
    asm("mov esp, eax");
    asm("mov ax, ds");
    asm("mov fs, ax");
#else
#error Brak CPU?
#endif

    int ret = setjmp(Core::Globals::process_exit_point);
    if (ret == 0) {
        int ec = imageEntryPoint();
        Core::WinAPI::ProcessThread::ExitProcess(
            static_cast<DWORD>(ec)
        );
    }

#if defined(CPU64)
    asm("mov rax, %0"::"r"(old_stack_pointer));
    asm("mov rsp, rax");
    asm("pop rax");
#elif defined(CPU32)
    asm("mov eax, %0"::"r"(old_stack_pointer));
    asm("mov esp, eax");
    asm("pop ax");
    asm("mov fs, ax");
    asm("pop eax");
#endif

}


}

