#include <cstdio>
#include <unistd.h>
#include <csetjmp>

std::jmp_buf test;
constexpr int LongJumpMagic = 42;
void f4(void) {
    printf("1\n");
    std::longjmp(test, LongJumpMagic);
    printf("2\n");
}
void f3(void) {f4();}
void f2(void) {f3();}
void f1(void) {f2();}

int main(void) {

    int x = setjmp(test);
    if (x == 0)
        f1();

    printf("?");
    return 0;
}