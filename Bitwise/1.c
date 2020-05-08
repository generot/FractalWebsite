#include <stdio.h>
#include <stdlib.h>

#define ONE 1
#define TWO 2
#define THREE 4

void PrintSmth(int a){
    if(a & ONE)
        printf("1");
    if(a & TWO)
        printf("2");
    if(a & THREE)
        printf("3");
    printf("\n");
}

int main(){
    PrintSmth(ONE);
    PrintSmth(ONE | TWO);
    PrintSmth(ONE | TWO | THREE);
}