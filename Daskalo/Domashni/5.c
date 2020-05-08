#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n;
    scanf("%d",&n);

    int arr1[n], arr2[n], arr3[n];
    printf("Array #1\tArray #2\tArray #3\n");

    srand(time(0));
    for(int i = 0; i < n; i++){
        arr1[i] = rand()%101;
        arr2[i] = rand()%101;
        if(arr1[i] > arr2[i]) arr3[i] = arr1[i];
        else arr3[i] = arr2[i];
    }

    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\n",arr1[i],arr2[i],arr3[i]);
    }
    
    return 0;
}