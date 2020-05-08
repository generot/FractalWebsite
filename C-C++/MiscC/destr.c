#include <stdio.h>
#include <stdlib.h>

void _Destroy(int **mem){
    if(*mem) free(*mem);
    printf("\nMemory freed.\n");
}

#define DESTROY __attribute__((__cleanup__(_Destroy)))

int main(){
    int *ptr DESTROY = malloc(10*sizeof(int));

    for(int i = 0; i < 10; i++)
        ptr[i] = rand()%20;

    for(int j = 0; j < 10; j++)
        printf("%d ", ptr[j]);

    return 0;
}