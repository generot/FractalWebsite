#include <stdio.h>
#include <stdlib.h>

#define BITS 8
int main(){
    __int8 a = 16;
    for(int b = 0; b < BITS; b++){
        if(a & (a >> b))
            printf("+");
        else printf("-");
    }
    return 0;
}