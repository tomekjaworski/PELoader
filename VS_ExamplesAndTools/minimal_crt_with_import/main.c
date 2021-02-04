#include <Windows.h>

//
// Wykorzystane funkcje: OutputDebugStringA, Sleep
//

int raw_main() {

    int a = 10;
    int b = 20;
    int c = 34;

    OutputDebugString("Ala");
    Sleep(1000);
    OutputDebugString(" ma ");
    Sleep(1000);
    OutputDebugString("kota.");
   //DebugBreak();
    return 42;
}
