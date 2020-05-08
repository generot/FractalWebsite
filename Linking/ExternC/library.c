#include <stdio.h>
#include <stdlib.h>

int* Bubblesort(int *toSort, size_t size){
    int *toRet = toSort, maxIter = 500;

    for(int j = 0; j < maxIter; j++){
        for(int i = 0; i < size-1; i++){
            if(toRet[i] > toRet[i+1]){
                int temp = toRet[i];

                toRet[i] = toRet[i+1];
                toRet[i+1] = temp;
            }
        }
    }

    return toRet;
}

int Power(int num, int pow){
    int k = 1;
    for(int i = 0; i < pow; i++)
        k*=num;
    return k;
}
