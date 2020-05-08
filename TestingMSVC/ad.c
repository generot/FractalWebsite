#include <stdio.h>

int main(){
    int a, k = 0, array[16] = {0};

    scanf("%d",&a);
    if(a >= 0 && a < 1025){
        for(;a > 0;a/=2){
            array[k] = a%2;
            k++;
        }
        for(int i = 15; i >= 0; i--)
            printf("%d",array[i]);
    }

    return 0;
}