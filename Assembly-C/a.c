#include <stdio.h>

int main(){
    int b = 3;
    int a;

    //Have to specify -masm=intel when compiling
    asm("mov eax, %1;"
        "inc eax;"
        "mov %0, eax;"
        :"=r"(a)
        :"r"(b)
        :"eax");

    
    printf("%d",a);
    return 0;
}