#include <stdio.h>
#include <stdlib.h>

#define SET_BIT(POS, INT) (INT |= (1 << (POS-1)))
int main(){
    unsigned int s, c;
    scanf("%d %d",&s,&c);

    SET_BIT(c,s);
    for(int i = 32; i > -1; i--){
        if(s & (1 << i))
            printf("1");
        else printf("0");
    }
    printf("\n%d",s);
}