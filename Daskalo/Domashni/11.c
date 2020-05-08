#include <stdio.h>

void Power(int x, int y){
    double n = 1;
    for(int i = 0; i < (y >= 0 ? y : -y); i++){
        n *= x;
    }

    if(y >= 0){
        printf("%.1lf\n", n);
    } else {
        printf("%lf\n", 1/n);
    }
}

int main(){
    int a, b;

    scanf("%d %d", &a, &b);
    Power(a, b);

    return 0;
}