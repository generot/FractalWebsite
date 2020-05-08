#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int *ptr = calloc(5,sizeof(int));
    int g[5] = {0};

    if(memcmp(ptr, g, 5*sizeof(int)) == 0)
        printf("zero");
    
    return EXIT_SUCCESS;
}
