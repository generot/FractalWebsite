#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    scanf("%d",&a);
    if(a == 1)
        printf("one");
    else if(a == 2)
        printf("two");
    else if(a == 3)
        printf("three");
    else printf("No such number");
    return 0; 
}