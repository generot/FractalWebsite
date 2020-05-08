#include <stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    switch(a){
        case 1: printf("edno");break;
        default: if(a >= 2){
            switch(a%2){
                case 0: printf("even");
                break;
                case 1: printf("odd");
                break;
            }
        }
        break;
    }
    return 0;
}