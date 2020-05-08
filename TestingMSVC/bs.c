#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned char a;
    scanf("%d",&a);
    for(int i = 8; i > -1; i--){
        if(a & (1 << i))
            printf("1");
        else printf("0");
    }

}