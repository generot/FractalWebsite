#include <stdio.h>

#define LINE "Right string."

#ifdef __MACRO__
#warning Warning #2124: __MACRO__ is defined.
#define LINE "Wrong string."
#endif

int main(){
    puts(LINE);
    return 0;
}