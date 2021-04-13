
# PE Loader


PELoader is a **WinAPI kernel/user call emulator**, able to run on **POSIX** platforms (Linux).
Currently, PELoader supports only a small subset of **kernel32.dll** functions. 

The input should be given in a form of a valid **PE** (Portable Execution) image file.
Loader tries to recreate executive environment that Windows creates for its processes and
to run the given image in it.
Hence, there is no virtualization nor translation undergoing -- the given program file is run *nativel*y on the host operating system.

PELoader is able to run both 32 and 64 bit PE images.
However, due to architecture differences 32 code can be run by 32 bit build of PELoader
and the same in the second case.


### Example
The following console dump was gathered for 64 bit version of the PELoader, running example *simple_output.exe*.

```
/root/Desktop/PELoader/cmake-build-debug/Core/Core64
Simple WinApi Emulator; (C) 2021 Tomasz Jaworski
Build for 64 bits; Compiled on Apr 13 2021 12:50:35
Number of available emulations: 92
PID=10795
VM page size: 4096

Number of sections: 7
Loading section .text...
VirtualAddress: 0x140001000, Pages: 17, SizeOfRawData: 69120; Bytes copied: 68848
Flags: 60000020
Loading section .rdata...
VirtualAddress: 0x140012000, Pages: 10, SizeOfRawData: 40448; Bytes copied: 40020
Flags: 40000040
Loading section .data...
VirtualAddress: 0x14001c000, Pages: 2, SizeOfRawData: 3072; Bytes copied: 3072
Flags: c0000040
Loading section .pdata...
VirtualAddress: 0x14001e000, Pages: 2, SizeOfRawData: 4608; Bytes copied: 4116
Flags: 40000040
Loading section _RDATA...
VirtualAddress: 0x140020000, Pages: 1, SizeOfRawData: 512; Bytes copied: 148
Flags: 40000040
Loading section .rsrc...
VirtualAddress: 0x140021000, Pages: 1, SizeOfRawData: 512; Bytes copied: 480
Flags: 40000040
Loading section .reloc...
VirtualAddress: 0x140022000, Pages: 1, SizeOfRawData: 2048; Bytes copied: 1644
Flags: 42000040
### Loading imports...
Linking OutputDebugStringA from kernel32.dll at 0x140012000... Ok!
Linking Sleep from kernel32.dll at 0x140012008... Ok!
Linking WriteConsoleW from kernel32.dll at 0x140012010... Ok!
Linking RtlCaptureContext from kernel32.dll at 0x140012018... Ok!
Linking RtlLookupFunctionEntry from kernel32.dll at 0x140012020... Ok!
Linking RtlVirtualUnwind from kernel32.dll at 0x140012028... Ok!
Linking UnhandledExceptionFilter from kernel32.dll at 0x140012030... Ok!
Linking SetUnhandledExceptionFilter from kernel32.dll at 0x140012038... Ok!
Linking GetCurrentProcess from kernel32.dll at 0x140012040... Ok!
Linking TerminateProcess from kernel32.dll at 0x140012048... Ok!
Linking IsProcessorFeaturePresent from kernel32.dll at 0x140012050... Ok!
Linking QueryPerformanceCounter from kernel32.dll at 0x140012058... Ok!
Linking GetCurrentProcessId from kernel32.dll at 0x140012060... Ok!
Linking GetCurrentThreadId from kernel32.dll at 0x140012068... Ok!
Linking GetSystemTimeAsFileTime from kernel32.dll at 0x140012070... Ok!
Linking InitializeSListHead from kernel32.dll at 0x140012078... Ok!
Linking IsDebuggerPresent from kernel32.dll at 0x140012080... Ok!
Linking GetStartupInfoW from kernel32.dll at 0x140012088... Ok!
Linking GetModuleHandleW from kernel32.dll at 0x140012090... Ok!
Linking RtlUnwindEx from kernel32.dll at 0x140012098... Ok!
Linking GetLastError from kernel32.dll at 0x1400120a0... Ok!
Linking SetLastError from kernel32.dll at 0x1400120a8... Ok!
Linking EnterCriticalSection from kernel32.dll at 0x1400120b0... Ok!
Linking LeaveCriticalSection from kernel32.dll at 0x1400120b8... Ok!
Linking DeleteCriticalSection from kernel32.dll at 0x1400120c0... Ok!
Linking InitializeCriticalSectionAndSpinCount from kernel32.dll at 0x1400120c8... Ok!
Linking TlsAlloc from kernel32.dll at 0x1400120d0... Ok!
Linking TlsGetValue from kernel32.dll at 0x1400120d8... Ok!
Linking TlsSetValue from kernel32.dll at 0x1400120e0... Ok!
Linking TlsFree from kernel32.dll at 0x1400120e8... Ok!
Linking FreeLibrary from kernel32.dll at 0x1400120f0... Ok!
Linking GetProcAddress from kernel32.dll at 0x1400120f8... Ok!
Linking LoadLibraryExW from kernel32.dll at 0x140012100... Ok!
Linking RaiseException from kernel32.dll at 0x140012108... Ok!
Linking GetStdHandle from kernel32.dll at 0x140012110... Ok!
Linking WriteFile from kernel32.dll at 0x140012118... Ok!
Linking GetModuleFileNameW from kernel32.dll at 0x140012120... Ok!
Linking ExitProcess from kernel32.dll at 0x140012128... Ok!
Linking GetModuleHandleExW from kernel32.dll at 0x140012130... Ok!
Linking GetCommandLineA from kernel32.dll at 0x140012138... Ok!
Linking GetCommandLineW from kernel32.dll at 0x140012140... Ok!
Linking HeapAlloc from kernel32.dll at 0x140012148... Ok!
Linking HeapFree from kernel32.dll at 0x140012150... Ok!
Linking CompareStringW from kernel32.dll at 0x140012158... Ok!
Linking LCMapStringW from kernel32.dll at 0x140012160... Ok!
Linking GetFileType from kernel32.dll at 0x140012168... Ok!
Linking FindClose from kernel32.dll at 0x140012170... Ok!
Linking FindFirstFileExW from kernel32.dll at 0x140012178... Ok!
Linking FindNextFileW from kernel32.dll at 0x140012180... Ok!
Linking IsValidCodePage from kernel32.dll at 0x140012188... Ok!
Linking GetACP from kernel32.dll at 0x140012190... Ok!
Linking GetOEMCP from kernel32.dll at 0x140012198... Ok!
Linking GetCPInfo from kernel32.dll at 0x1400121a0... Ok!
Linking MultiByteToWideChar from kernel32.dll at 0x1400121a8... Ok!
Linking WideCharToMultiByte from kernel32.dll at 0x1400121b0... Ok!
Linking GetEnvironmentStringsW from kernel32.dll at 0x1400121b8... Ok!
Linking FreeEnvironmentStringsW from kernel32.dll at 0x1400121c0... Ok!
Linking SetEnvironmentVariableW from kernel32.dll at 0x1400121c8... Ok!
Linking SetStdHandle from kernel32.dll at 0x1400121d0... Ok!
Linking GetStringTypeW from kernel32.dll at 0x1400121d8... Ok!
Linking GetProcessHeap from kernel32.dll at 0x1400121e0... Ok!
Linking FlushFileBuffers from kernel32.dll at 0x1400121e8... Ok!
Linking GetConsoleCP from kernel32.dll at 0x1400121f0... Ok!
Linking GetConsoleMode from kernel32.dll at 0x1400121f8... Ok!
Linking GetFileSizeEx from kernel32.dll at 0x140012200... Ok!
Linking SetFilePointerEx from kernel32.dll at 0x140012208... Ok!
Linking HeapSize from kernel32.dll at 0x140012210... Ok!
Linking HeapReAlloc from kernel32.dll at 0x140012218... Ok!
Linking CloseHandle from kernel32.dll at 0x140012220... Ok!
Linking CreateFileW from kernel32.dll at 0x140012228... Ok!
Calling entry point 0x1400013c4 with stack 0x7f1e512e4000-0x7f1e514e3000...
[NOT IMPLEMENTED] WCHAR* Core::WinAPI::ProcessEnv::GetEnvironmentStringsW()
[NOT IMPLEMENTED] void* Core::WinAPI::ErrorHandling::SetUnhandledExceptionFilter(Core::WinAPI::ErrorHandling::LPTOP_LEVEL_EXCEPTION_FILTER)
DEBUG: Ala ma kota
Ala ma kota i zubra, bobra, losia, lisa, wilka, kune, konia, wydre, ryjowke oraz zajaca.[NOT IMPLEMENTED] void* Core::WinAPI::LibLoader::GetModuleHandleW(LPCWSTR)
[NOT IMPLEMENTED] void* Core::WinAPI::LibLoader::GetModuleHandleW(LPCWSTR)
[NOT IMPLEMENTED] BOOL Core::WinAPI::LibLoader::GetModuleHandleExW(DWORD, LPCWSTR, void**)
Entry point 0x1400013c4 has returned...
Exit error code: 123
[Clean exit]
```
