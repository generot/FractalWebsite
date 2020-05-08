#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d",&n);
    int array[n], num = 0;

    if(n <= 10) //Границата е 10, защото ограничението(999) е 10 бита.
        for(int i = n-1; i >= 0; i--){
            scanf("%d",&array[i]);
            num += array[i] * pow(2,i);
        }
    else printf("Out of bounds, the number of bits can't be over 10");

    if(num < 1000) printf("%d",num);
    else printf("Out of bounds, the number is too big");

    return 0;
}