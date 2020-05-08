#include <stdio.h>
#include <stdarg.h>
int Callback(int a,...){
    va_list vl;
    int sum = 0;

    va_start(vl,a);
    for(int i = 0; i < a; i++){
        sum += va_arg(vl, int);
    }
    va_end(vl);

    return sum;
}
int main(){
    int cnt = 3;
    printf("%d",Callback(cnt,4,5,6));
    return 0;
}