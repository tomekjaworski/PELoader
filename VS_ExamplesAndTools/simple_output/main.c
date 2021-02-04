// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>

const char* animals[] = {
    "zubra",
    "bobra",
    "losia",
    "lisa",
    "wilka",
    "kune",
    "konia",
    "wydre",
    "ryjowke",
    "zajaca",
    NULL
};

int main()
{
    OutputDebugStringA("Ala ma kota");
    printf("Ala ma kota i");
    for (int i = 0; animals[i] != NULL; i++) {
        if (animals[i + 1] == NULL)
            printf(" oraz %s.", animals[i]);
        else {
            if (i > 0)
                printf(",");
            printf(" %s", animals[i]);
        }
        Sleep(500);
    }
    return 123;
}
