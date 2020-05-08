#include <stdio.h>
#include <string.h>

int main(){
    int n, bits = 10, bin[bits], index = 0; //10 бита, понеже крайната ни граница(999) е 10 бита.
    memset(bin, 0, bits*sizeof(int));

    scanf("%d",&n);

    if(n >= 0 && n < 1000){
        for(;n > 0;n /= 2){
            bin[index] = n%2;
            index++;
        }
        for(int i = bits-1; i >= 0; i--)
            printf("%d",bin[i]);
    } else printf("Out of bounds");
    return 0;
}