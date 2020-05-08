#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *str1 = "String", *str2 = NULL;
    size_t sz = sizeof "String";
    str2 = malloc(sz);

    while(*str2++ = *str1++);
    printf("%s\n%s", str1 - sz, str2 - sz);
    free(str2);
    return 0;
}