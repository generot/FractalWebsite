#include <stdio.h>
#include <math.h>

int main(){
    int inp;
    scanf("%d",&inp);

    int a[inp], number = 0;

    if(inp < 1000){
        for(int i = 0; i < inp; i++){
            int num, divisors = 0;
            scanf("%d",&num);

            for(int i = 1; i <= num; i++){
                if(num%i == 0)
                    divisors++;
            }

            if(divisors == 2) a[i] = 0;
            else a[i] = 1;
        }
    } else printf("Out of bounds.");

    for(int j = inp-1; j >= 0; j--){
        number += a[j] * pow(2,inp-j-1);
    }

    printf("%d",number);
    
    return 0;
}