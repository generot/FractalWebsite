#include <stdio.h>

double Power(int a, int b);

int main(){
    int a, b;
    double sum = 0;

    scanf("%d%d", &a, &b);

    for(int i = 1; i <= a; i++){
        sum += Power(i, b);
    }
    printf("%.3lf", sum);
    return 0;
}

double Power(int a, int b){
    double power = 1;
    for(int i = 0; i < (b < 0 ? -b : b); i++){
        power *= a;
    }
    if(b >= 0) {
        return power;
    }
    else {
        return 1/power;
    }
}