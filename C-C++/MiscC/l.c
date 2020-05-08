#include <stdio.h>
#include <stdlib.h>

void FreeMem(int **ptr){
    if(*ptr) free(*ptr);
    printf("\nMemory freed\n");
}

#define RAII_VAR __attribute__((__cleanup__(FreeMem)))
#define SINT_PTR RAII_VAR int*

int main(){
    SINT_PTR ptr = malloc(40);

    for(int i = 0; i < 4; i++)
        ptr[i] = rand()%20;
    for(int i = 0; i < 4; i++)
        printf("%d ", ptr[i]);

    return 0;
}