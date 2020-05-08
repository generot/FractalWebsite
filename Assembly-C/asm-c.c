#include <stdio.h>
void Swap(int *a, int *b);
int main(){
    int c = 3, d = 4;
    Swap(&c,&d);
    printf("c - %d, d - %d", c, d);
    return 0;
}
void Swap(int *a, int *b){
    int aS = *a;
    asm("movl %1, %0;"
        :"=r"(*a)
        :"r"(*b));
    *b = aS;
}