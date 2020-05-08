#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    __asm__("movl $3, %eax");
    register int i asm("eax");
    a = i;
    printf("%d",a);
}