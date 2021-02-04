#include <list>
#include <cassert>

#include "BasicTypes.hpp"
#include "BasicMacros.hpp"
#include "../WinApiFunction.h"


void __dead_end_call(void) {
    assert(false && "Lista wywołań WINAPI wymaga uzupełnień!");
}

//
//
//


#include "Console/Console.hpp"
#include "Debug/Debug.hpp"
#include "ErrorHandling/ErrorHandling.hpp"
#include "File/File.hpp"
#include "Handle/Handle.hpp"
#include "Heap/Heap.hpp"
#include "Interlocked/Interlocked.hpp"
#include "LibLoader/LibLoader.hpp"
#include "NLS/NLS.hpp"
#include "ProcessEnvironment/ProcesEnv.hpp"
#include "ProcessThread/ProcessThread.hpp"
#include "Profile/Profile.hpp"
#include "Strings/Strings.hpp"
#include "Synchronization/Synchronization.hpp"
#include "SysInfo/SysInfo.hpp"
#include "Util/Util.hpp"
#include "WinNT/WinNT.hpp"

namespace Core::WinAPI {

void Kernel32_RegisterLibrary(std::list<WinApiFunction>& availableEmulations) {

    auto reg = [&availableEmulations](WinApiFunction function) {
        availableEmulations.push_back(function);
    };

    reg(WinApiFunction("kernel32.dll", "Sleep", Core::WinAPI::Synchronization::Sleep));
    reg(WinApiFunction("kernel32.dll", "SleepEx", Core::WinAPI::Synchronization::SleepEx));
    reg(WinApiFunction("kernel32.dll", "OutputDebugStringA", Core::WinAPI::Debug::OutputDebugStringA));
    reg(WinApiFunction("kernel32.dll", "DebugBreak", Core::WinAPI::Debug::DebugBreak));

    reg(WinApiFunction("kernel32.dll", "WriteConsoleW", Core::WinAPI::Console::WriteConsoleW));
    reg(WinApiFunction("kernel32.dll", "RtlCaptureContext", Core::WinAPI::WinNT::RtlCaptureContext));
    reg(WinApiFunction("kernel32.dll", "RtlLookupFunctionEntry", Core::WinAPI::WinNT::RtlLookupFunctionEntry));
    reg(WinApiFunction("kernel32.dll", "RtlVirtualUnwind", Core::WinAPI::WinNT::RtlVirtualUnwind));
    reg(WinApiFunction("kernel32.dll", "UnhandledExceptionFilter",
                       Core::WinAPI::ErrorHandling::UnhandledExceptionFilter));
    reg(WinApiFunction("kernel32.dll", "SetUnhandledExceptionFilter",
                       Core::WinAPI::ErrorHandling::SetUnhandledExceptionFilter));
    reg(WinApiFunction("kernel32.dll", "GetCurrentProcess", Core::WinAPI::ProcessThread::GetCurrentProcess));
    reg(WinApiFunction("kernel32.dll", "TerminateProcess", Core::WinAPI::ProcessThread::TerminateProcess));
    reg(WinApiFunction("kernel32.dll", "IsProcessorFeaturePresent",
                       Core::WinAPI::ProcessThread::IsProcessorFeaturePresent));
    reg(WinApiFunction("kernel32.dll", "QueryPerformanceCounter", Core::WinAPI::Profile::QueryPerformanceCounter));
    reg(WinApiFunction("kernel32.dll", "GetCurrentProcessId", Core::WinAPI::ProcessThread::GetCurrentProcessId));
    reg(WinApiFunction("kernel32.dll", "GetCurrentThreadId", Core::WinAPI::ProcessThread::GetCurrentThreadId));
    reg(WinApiFunction("kernel32.dll", "GetSystemTimeAsFileTime", Core::WinAPI::SysInfo::GetSystemTimeAsFileTime));
    reg(WinApiFunction("kernel32.dll", "InitializeSListHead", Core::WinAPI::Interlocked::InitializeSListHead));
    reg(WinApiFunction("kernel32.dll", "IsDebuggerPresent", Core::WinAPI::Debug::IsDebuggerPresent));
    reg(WinApiFunction("kernel32.dll", "GetStartupInfoW", Core::WinAPI::ProcessThread::GetStartupInfoW));
    reg(WinApiFunction("kernel32.dll", "GetModuleHandleW", Core::WinAPI::LibLoader::GetModuleHandleW));
    reg(WinApiFunction("kernel32.dll", "RtlUnwindEx", Core::WinAPI::WinNT::RtlUnwindEx));
    reg(WinApiFunction("kernel32.dll", "GetLastError", Core::WinAPI::ErrorHandling::GetLastError));
    reg(WinApiFunction("kernel32.dll", "SetLastError", Core::WinAPI::ErrorHandling::SetLastError));
    reg(WinApiFunction("kernel32.dll", "EnterCriticalSection", Core::WinAPI::Synchronization::EnterCriticalSection));
    reg(WinApiFunction("kernel32.dll", "LeaveCriticalSection", Core::WinAPI::Synchronization::LeaveCriticalSection));
    reg(WinApiFunction("kernel32.dll", "DeleteCriticalSection", Core::WinAPI::Synchronization::DeleteCriticalSection));
    reg(WinApiFunction("kernel32.dll", "InitializeCriticalSectionAndSpinCount",
                       Core::WinAPI::Synchronization::InitializeCriticalSectionAndSpinCount));
    reg(WinApiFunction("kernel32.dll", "TlsAlloc", Core::WinAPI::ProcessThread::TlsAlloc));
    reg(WinApiFunction("kernel32.dll", "TlsGetValue", Core::WinAPI::ProcessThread::TlsGetValue));
    reg(WinApiFunction("kernel32.dll", "TlsSetValue", Core::WinAPI::ProcessThread::TlsSetValue));
    reg(WinApiFunction("kernel32.dll", "TlsFree", Core::WinAPI::ProcessThread::TlsFree));
    reg(WinApiFunction("kernel32.dll", "FreeLibrary", Core::WinAPI::LibLoader::FreeLibrary));
    reg(WinApiFunction("kernel32.dll", "GetProcAddress", Core::WinAPI::LibLoader::GetProcAddress));
    reg(WinApiFunction("kernel32.dll", "LoadLibraryExW", Core::WinAPI::LibLoader::LoadLibraryExW));
    reg(WinApiFunction("kernel32.dll", "RaiseException", Core::WinAPI::ErrorHandling::RaiseException));
    reg(WinApiFunction("kernel32.dll", "GetStdHandle", Core::WinAPI::Console::GetStdHandle));
    reg(WinApiFunction("kernel32.dll", "WriteFile", Core::WinAPI::File::WriteFile));
    reg(WinApiFunction("kernel32.dll", "DeleteFileW", Core::WinAPI::File::DeleteFileW));
    reg(WinApiFunction("kernel32.dll", "GetModuleFileNameW", Core::WinAPI::LibLoader::GetModuleFileNameW));
    reg(WinApiFunction("kernel32.dll", "ExitProcess", Core::WinAPI::ProcessThread::ExitProcess));
    reg(WinApiFunction("kernel32.dll", "GetModuleHandleExW", Core::WinAPI::LibLoader::GetModuleHandleExW));
    reg(WinApiFunction("kernel32.dll", "GetCommandLineA", Core::WinAPI::ProcessEnv::GetCommandLineA));
    reg(WinApiFunction("kernel32.dll", "GetCommandLineW", Core::WinAPI::ProcessEnv::GetCommandLineW));
    reg(WinApiFunction("kernel32.dll", "HeapAlloc", Core::WinAPI::Heap::HeapAlloc));
    reg(WinApiFunction("kernel32.dll", "HeapFree", Core::WinAPI::Heap::HeapFree));
    reg(WinApiFunction("kernel32.dll", "CompareStringW", Core::WinAPI::Strings::CompareStringW));
    reg(WinApiFunction("kernel32.dll", "LCMapStringW", Core::WinAPI::Strings::LCMapStringW));
    reg(WinApiFunction("kernel32.dll", "GetFileType", Core::WinAPI::File::GetFileType));
    reg(WinApiFunction("kernel32.dll", "FindClose", Core::WinAPI::File::FindClose));
    reg(WinApiFunction("kernel32.dll", "FindFirstFileExW", Core::WinAPI::File::FindFirstFileExW));
    reg(WinApiFunction("kernel32.dll", "FindNextFileW", Core::WinAPI::File::FindNextFileW));
    reg(WinApiFunction("kernel32.dll", "IsValidCodePage", Core::WinAPI::NLS::IsValidCodePage));
    reg(WinApiFunction("kernel32.dll", "GetACP", Core::WinAPI::NLS::GetACP));
    reg(WinApiFunction("kernel32.dll", "GetOEMCP", Core::WinAPI::NLS::GetOEMCP));
    reg(WinApiFunction("kernel32.dll", "GetCPInfo", Core::WinAPI::NLS::GetCPInfo));
    reg(WinApiFunction("kernel32.dll", "MultiByteToWideChar", Core::WinAPI::Strings::MultiByteToWideChar));
    reg(WinApiFunction("kernel32.dll", "WideCharToMultiByte", Core::WinAPI::Strings::WideCharToMultiByte));
    reg(WinApiFunction("kernel32.dll", "GetEnvironmentStringsW", Core::WinAPI::ProcessEnv::GetEnvironmentStringsW));
    reg(WinApiFunction("kernel32.dll", "FreeEnvironmentStringsW", Core::WinAPI::ProcessEnv::FreeEnvironmentStringsW));
    reg(WinApiFunction("kernel32.dll", "SetEnvironmentVariableW", Core::WinAPI::ProcessEnv::SetEnvironmentVariableW));
    reg(WinApiFunction("kernel32.dll", "SetStdHandle", Core::WinAPI::Console::SetStdHandle));
    reg(WinApiFunction("kernel32.dll", "GetStringTypeW", Core::WinAPI::Strings::GetStringTypeW));
    reg(WinApiFunction("kernel32.dll", "GetProcessHeap", Core::WinAPI::Heap::GetProcessHeap));
    reg(WinApiFunction("kernel32.dll", "FlushFileBuffers", Core::WinAPI::File::FlushFileBuffers));
    reg(WinApiFunction("kernel32.dll", "GetConsoleCP", Core::WinAPI::Console::GetConsoleCP));
    reg(WinApiFunction("kernel32.dll", "GetConsoleMode", Core::WinAPI::Console::GetConsoleMode));
    reg(WinApiFunction("kernel32.dll", "GetFileSizeEx", Core::WinAPI::File::GetFileSizeEx));
    reg(WinApiFunction("kernel32.dll", "SetFilePointerEx", Core::WinAPI::File::SetFilePointerEx));
    reg(WinApiFunction("kernel32.dll", "HeapSize", Core::WinAPI::Heap::HeapSize));
    reg(WinApiFunction("kernel32.dll", "HeapReAlloc", Core::WinAPI::Heap::HeapReAlloc));
    reg(WinApiFunction("kernel32.dll", "CloseHandle", Core::WinAPI::Handle::CloseHandle));
    reg(WinApiFunction("kernel32.dll", "CreateFileW", Core::WinAPI::File::CreateFileW));
    reg(WinApiFunction("kernel32.dll", "ReadFile", Core::WinAPI::File::ReadFile));

    reg(WinApiFunction("kernel32.dll", "EncodePointer", Core::WinAPI::Util::EncodePointer));
    reg(WinApiFunction("kernel32.dll", "DecodePointer", Core::WinAPI::Util::DecodePointer));


    //
    // Puste protezy:
    //

    reg(WinApiFunction("kernel32.dll", "VirtualQuery", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "InterlockedPushEntrySList", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "InterlockedFlushSList", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "RtlPcToFileHeader", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "GetDateFormatW", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "GetTimeFormatW", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "GetLocaleInfoW", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "IsValidLocale", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "GetUserDefaultLCID", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "EnumSystemLocalesW", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "GetCurrentThread", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "OutputDebugStringW", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "SetConsoleCtrlHandler", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "ReadConsoleW", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "RtlUnwind", __dead_end_call));
    reg(WinApiFunction("kernel32.dll", "SetEndOfFile", __dead_end_call));

}

}


