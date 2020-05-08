#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ 200
int main(){
    char *ptr = malloc(SZ);
    memset(ptr,10,SZ);
    for(int i = 0; i < SZ; i++){
        printf("%d",ptr[i]);
    }
    free(ptr);
}