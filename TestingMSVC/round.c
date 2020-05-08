#include <stdio.h>

int Round(float b);
int main(){
    float a;
    scanf("%f",&a);
    printf("%d",Round(a));
    return 0;
}
int Round(float b){
    float temp = b - (int)b;
    if(temp >= 0.5)
        return (int)b + 1;
    else return (int)b;
}