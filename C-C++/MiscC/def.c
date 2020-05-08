#include <stdio.h>

#if defined(__MINGW64__)
#define STR "Hello"
#else 
#define STR "NO"
#endif

int main(){
    printf(STR);
    return 0;
}