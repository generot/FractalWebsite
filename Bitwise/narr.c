#include <stdio.h>
#include <stdlib.h>

#define BITS 32
#define GRP_SZ 4

typedef struct _int4{
    unsigned int a:4;
} int4;

int main(){
    unsigned int input;
    char *str = "0123456789ABCDEF";

    scanf("%ui", &input);
    printf("0x");

    for(int i = BITS/GRP_SZ; i > 0 ; i--){
        int4 group = {0};
        for(int j = 0; j < GRP_SZ; j++)
            if(input & (1 << (i*GRP_SZ - j - 1))) group.a |= (1 << (GRP_SZ - j - 1));

        if(group.a == 0) printf("%d",group.a);
        for(;group.a > 0;group.a/=16)
            printf("%c",str[group.a%16]);
    }

    return EXIT_SUCCESS;
}