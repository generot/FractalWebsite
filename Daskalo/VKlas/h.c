#include <stdio.h>

void powfunc(int x, int y){
    int n = 1;
    for(int i = 0; i < y; i++){
        n*=x; //n = n*x
    }
    printf("%d", n);
}

int main(){
    int a, b;

    scanf("%d %d", &a, &b);
    powfunc(a, b);

    return 0;
}