#include <stdio.h>
#include <stdlib.h>
int main(){
    char *ptr = malloc(20);

    //Tazi konstrukcija ne e losha
    scanf("%19[^\n]s", ptr);
    printf("%s",ptr);

    free(ptr);
    return 0;
}