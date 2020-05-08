#include <stdio.h>
#include <stdlib.h>

#define SIZE 32
#define GRP_SZ 4

int Power(int a, int b);

int main(){
    unsigned __int64 inp;
    char *chars = "0123456789ABCDEF", output[16];
    int i, sum, j;

    i = j = sum = 0;
    
    scanf("%llu", &inp);

    for(;inp > 0; inp/=10){
        sum += (inp%10) * Power(2,i);
        i++;
    }

    for(;sum > 0; sum/=16) {
        output[j] = chars[sum%16];
        j++;
    }

    printf("0x");
    output[j] = '\0';
    for(int g = j-1; g > -1; g--) printf("%c", output[g]);

    return EXIT_SUCCESS;
}

int Power(int a, int b){
    int n = 1;
    for(int i = 0; i < b; i++) n*=a;
    return n;
}