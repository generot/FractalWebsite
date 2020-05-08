#include <stdio.h>
#include <stdlib.h>


int main(){
    int in, i = 0;
    char *output = malloc(20*sizeof(char));
    scanf("%d",&in);
    
    char *p = "0123456789ABCDEF";
    for(;in > 0; in/=16){
        int modulus = in%16;
        output[i] = p[modulus];
        output = realloc(output,(i+1)*sizeof(char));
        i++;
    }
    output[i] = '\0';

    printf("0x");
    for(int j = i-1; j >= 0; j--)
        printf("%c",output[j]);

    free(output);
    return EXIT_SUCCESS;
}
