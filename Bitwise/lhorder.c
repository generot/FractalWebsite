#include <stdio.h>
#include <stdarg.h>

void StuffIn32(int *addr, int lowOrder, int highOrder){
    int hO = highOrder;
    *addr = lowOrder;

    hO = hO << 16;
    *addr |= hO; 
}

void CheckBits(int amount, ...){
    va_list list;
    va_start(list, amount);

    for(int i = 0; i < amount; i++){
        int curr = va_arg(list, int);
        printf("%d - ", curr);

        for(int j = 31; j >= 0; j--){
            if(curr & (1 << j))
                printf("1");
            else printf("0");
        }

        printf("\n");
    }

    va_end(list);
}

int main(){

    int a = 120, b = 135, c = 0;

    StuffIn32(&c, a, b);
    CheckBits(3, a, b, c);

    return 0;
}

