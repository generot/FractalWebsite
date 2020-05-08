#include <stdio.h>

int main(){
    int n, odd = 0;
    scanf("%d",&n);
    int a[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        if(a[i]%2)
            odd++;
    }

    printf("Even numbers - %.2f%% - %d, Odd numbers - %.2f%% - %d",100 - ((float)odd/n*100), n-odd, (float)odd/n*100, odd);
    return 0;
}