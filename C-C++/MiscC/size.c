#include <stdio.h>
#include <stdarg.h>

void PrintArgs(const char *fr, ...){
    va_list list;
    va_start(list, fr);
    vprintf(fr, list);
    va_end(list);
}

int main(){
    PrintArgs("Number one: %d, Letter 'D': %c", 3, 'D');
    return 0;
}