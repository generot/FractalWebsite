#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, k, sum, absSum;
    sum = absSum = 0;
    scanf("%d",&a);

    int array[a];
    char msg[] = "Error in the sequence. Enter again: ";

    for(int i = 0; i < a; i++){
        scanf("%d",&k);
        if(i%2==0){
            if(k > 0) array[i] = k;
            else {
                printf("%s\n",msg);
                i--;
                continue;
            }
        } else {
            if(k < 0) array[i] = k;
            else {
                printf("%s\n",msg);
                i--;
                continue;
            }
        }
    }

    for(int j = 0; j < a; j++){
        sum += array[j];
        absSum += abs(array[j]);
    }

    printf("The sum is: %d\nThe average of the absolute values is: %.2f",sum,(float)absSum/a);
    return 0;
}