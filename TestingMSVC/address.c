#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y);

int main(){
    int a, b;
    scanf("%d %d",&a,&b);
    Swap(&a,&b);

    printf("%d - %p\n%d - %p",a,&a,b,&b);
}
void Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}