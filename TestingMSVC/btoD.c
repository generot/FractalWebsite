#include <stdio.h>
#include <math.h>

int main(){
    unsigned long long k = 0;
    int dec, i;
    dec = i = 0;
    scanf("%llu",&k);

    for(;k>0;k/=10){
        dec += (k%10)*pow(2,i);
        i++;
    }

    printf("%d",dec);
    return 0;
}