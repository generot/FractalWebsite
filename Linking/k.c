#include <stdio.h>
#include <stdlib.h>

__attribute__((constructor)) void Init(){
    printf("Constructor called\n");
}

__attribute__((destructor)) void Destroy(){
    printf("Destructor called\n");
}

int main(){
    printf("In main...\n");
    return 0;
}