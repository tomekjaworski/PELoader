// sandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>

//
//__declspec(naked)
//uint64_t getTIB() {
//	__asm {
//		mov ax, cs
//		nop
//		mov ax, ds
//		nop
//		mov ax, es
//		nop
//		mov ax, fs
//		nop
//		mov ax, gs
//		nop
//
//		mov ax, fs
//		mov bx, 1111
//		mov ds, ax
//		mov fs,ax
//		mov gs,ax
//		mov gs, ax
//
//		mov EAX, dword ptr FS: [18h]
//		mov EAX, dword ptr FS : [10h]
//		nop
//		mov EAX, dword ptr gs : [18h]
//		mov EAX, dword ptr gS : [10h]
//		nop
//		mov EAX, dword ptr  dS : [18h]
//		mov EAX, dword ptr dS : [10h]
//		nop
//
//		ret
//	}
//}

struct Foo
{
	char c; 
	double d;
	short s;
	int i;
};

#include <vector>
int main()
{
	std::vector<int>* pv = new(std::nothrow) std::vector<int>();

	HMODULE k = LoadLibraryA("kernel32.dll");
	FARPROC proc1 = GetProcAddress(k, "Sleep");
	FARPROC proc2 = GetProcAddress(k, "sleep");
	FreeLibrary(k);
	GetProcAddress(k, "Sleep");
	int qqq = sizeof(CRITICAL_SECTION);

	qqq = sizeof(SIZE_T);

	//getTIB();

	//uint64_t* ptr = (uint64_t*)0x10000;
	//uint64_t val = *ptr;

	int qq = sizeof(struct Foo);
	Foo f;

	wchar_t buffer[MAX_PATH + 1];
	//GetModuleFileNameW()

	//BOOL b = IsValidCodePage(1250);
	SLIST_HEADER hd;
	qq = sizeof(SLIST_HEADER);
	qq = sizeof(SLIST_ENTRY);
	InitializeSListHead(&hd);

	//LPWCH es = GetEnvironmentStringsW();
	//LPCWCH ces = (LPCWCH)es;
	//while (*ces)
	//{
	//	printf("*** %S\n", ces);
	//	ces += lstrlen(ces) + 1;
	//}
	void* xax = EncodePointer(0);
	xax = DecodePointer(xax);
	//FreeEnvironmentStringsW(es);

	qq = sizeof(STARTUPINFOW);
	qq = sizeof(STARTUPINFOA);

	STARTUPINFOW si, * lpStartupInfo = &si;
	memset(lpStartupInfo, 0, sizeof(STARTUPINFOW));
	lpStartupInfo->cb = sizeof(STARTUPINFOA);
	//ERROR_ABANDONED_WAIT_0
	int q;
	q = GetACP();
	q = sizeof(SLIST_HEADER); // 4
	q = sizeof(int); // 4
	q = sizeof(INT); // 4
	q = sizeof(UINT); // 4
	q = sizeof(WCHAR); //  2
	q = sizeof(WORD); //  2
	q = sizeof(SHORT); //   2
	q = sizeof(BYTE); // 1
	q = sizeof(LONG); // 4
	q = sizeof(ULONG); // 4
	q = sizeof(DWORD); //  4
	q = sizeof(LONGLONG); //  8
	q = sizeof(ULONGLONG); //  8
	q = sizeof(HANDLE); // 8
	q = sizeof(HMODULE); //  8
	q = sizeof(HINSTANCE); //  8

#define static_assert(x) assert(x)
	static_assert(sizeof(BYTE) == 1);
	static_assert(sizeof(CHAR) == 1);

	static_assert(sizeof(WORD) == 2);
	static_assert(sizeof(SHORT) == 2);
	static_assert(sizeof(WCHAR) == 2);

	static_assert(sizeof(INT) == 4);
	static_assert(sizeof(UINT) == 4);

	static_assert(sizeof(LONG) == 4);
	static_assert(sizeof(ULONG) == 4);

	static_assert(sizeof(DWORD) == 4);
	static_assert(sizeof(BOOL) == 4);
	static_assert(sizeof(FLOAT) == 4);

	static_assert(sizeof(LONG_PTR) == sizeof(void*));
	static_assert(sizeof(ULONG_PTR) == sizeof(void*));

	static_assert(sizeof(SIZE_T) == sizeof(void*));
	static_assert(sizeof(SSIZE_T) == sizeof(void*));

	static_assert(sizeof(LONGLONG) == 8);
	static_assert(sizeof(ULONGLONG) == 8);

	static_assert(sizeof(HANDLE) == sizeof(void*));
	static_assert(sizeof(HMODULE) == sizeof(void*));
	static_assert(sizeof(HINSTANCE) == sizeof(void*));

	static_assert(sizeof(INT_PTR) == sizeof(void*));
	static_assert(sizeof(UINT_PTR) == sizeof(void*));

	static_assert(sizeof(FARPROC) == sizeof(void*));


	HANDLE hi = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE ho = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE he = GetStdHandle(STD_ERROR_HANDLE);
	DWORD _di = GetFileType(hi);
	DWORD _do = GetFileType(ho);
	DWORD _de = GetFileType(he);
	//_de = GetFileType((HANDLE)12345);

	//HANDLE hp = GetProcessHeap();
	//void* a = HeapAlloc(hp, 0, 0x100000000000);
	////HMODULE k = LoadLibrary(L"kernel32.dll");
	int err;
	err = GetLastError();
	//HMODULE k1 = LoadLibrary(L"kernel32fsdf.dll");
	//err = GetLastError();

	//FARPROC fp1 = GetProcAddress(k, "Sleep");
	//err = GetLastError();
	//FARPROC fp2 = GetProcAddress(k, "Sleep2");
	//err = GetLastError();
	//err = ERROR_SUCCESS;

	//TlsSetValue(123, (LPVOID)52);
	//DWORD id = TlsAlloc();
	//void* x = TlsGetValue(123);
	//ERROR_SUCCESS

	//int y = GetLastError();
	OutputDebugStringA("XXXXXXXXX");
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	DWORD thid = GetCurrentThreadId();

	//DebugBreak();

	//uint64_t* pp = (uint64_t*)(0x10);
	//uint64_t ppp = getTIB();

	printf("Hello World!\n");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
