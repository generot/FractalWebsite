#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubblesort(int *arr, size_t size){
    for(;;){
        int j, prev[size];
        memcpy(prev, arr, size*sizeof(int));
        for(int i = 0; i < size-1; i++){
            if(arr[i] < arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        if(!memcmp(prev, arr, size*sizeof(int))) break;
    }
}

#define MAX 40

int main(){
    int arr[MAX];
    srand(time(0));

    for(int i = 0; i < MAX; i++){
        arr[i] = rand()%30;
        printf("%d ", arr[i]);
    }

    bubblesort(arr,MAX);
    printf("\n");

    for(int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
    return 0;
}