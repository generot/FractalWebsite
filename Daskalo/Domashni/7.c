#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b = 10, inBinary[10] = {0}, ind = 0; //2^9

    scanf("%d",&a);
    if(a >= -512 && a <= 512){
        int absVal = abs(a);
        for(; absVal > 0; absVal /= 2){
            inBinary[ind] = absVal%2;
            ind++;
        }
        if(a < 0) inBinary[b-1] = 1;

        for(int j = b-1; j >= 0; j--)
            printf("%d",inBinary[j]);
         
    } else printf("Out of bounds.");

    return 0;
}