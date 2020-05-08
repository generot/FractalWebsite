#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d",&a,&b);

    char *strs[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    for(int i = a; i <= b; i++){
        int j = 0;
        for(int t = i; t > 0; t/=10)
            j++;
        if(j == 1 || i == 0)
            printf("%s\n",strs[i]);
        else {
            if(i%2 == 0)
                printf("even\n");
            else printf("odd\n");
        }
    }
    return 0;
}
