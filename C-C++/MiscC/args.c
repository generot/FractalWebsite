#include <stdio.h>
#include <stdarg.h>

int max(int a, ...){
    va_list list;
    int max;

    va_start(list, a);
    max = va_arg(list, int);

    for(int i = 0; i < 3; i++){
        int curr = va_arg(list, int);
        if(max < curr) max = curr;
    }
    return max;
}
int main(){
    printf("Max: %d", max(4,4,12,6,7));
    return 0;
}