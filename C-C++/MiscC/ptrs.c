#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char**argv){
    int n = atoi(argv[1]);

    char **ptr = (char**)calloc(n,sizeof(char*));
    for(int i = 0; i < n; i++){
        ptr[i] = (char*)calloc(n,sizeof(char));
        memset(ptr[i], atoi(argv[2]), n);
    }

    for(int j = 0; j < n; j++){
        for(int g = 0; g < n; g++){
            printf("%d ",ptr[g][j]);
        }
        printf("\n");
    }

    free(ptr);
    return 0;
}