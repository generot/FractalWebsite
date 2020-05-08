#include <stdio.h>

int main(){
    int inp;
    scanf("%d",&inp);

    int a[inp];

    if(inp < 1000){
        for(int i = 0; i < inp; i++){
            int num, divisors = 0;
            scanf("%d",&num);

            for(int a = 1; a <= num; a++){
                if(num%a == 0)
                    divisors++;
            }

            if(divisors == 2) a[i] = 0;
            else a[i] = 1;
        }

        printf("\n");

        for(int j = 0; j < inp; j++)
            printf("%d\n",a[j]);

    } else printf("Out of bounds.");
    
    return 0;
}