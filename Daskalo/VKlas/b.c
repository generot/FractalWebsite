#include <stdio.h>

int main(){
    int x, y, sum = 0;

    printf("Enter the number of rows: ");
    scanf("%d",&y);
    printf("Enter the number of columns: ");
    scanf("%d",&x);

    int array[x][y];

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            scanf("%d", &array[j][i]);
        }
    }

    printf("\n");

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            printf("%d ", array[j][i]);
        }
        printf("\n");
    }

    for(int i = 0; i < y; i++){
        sum = 0;
        for(int j = 0; j < x; j++){
            sum += array[j][i];
        }
        printf("Sum of row #%d: %d\n", i,sum);
    }

    for(int i = 0; i < x; i++){
        sum = 0;
        for(int j = 0; j < y; j++){
            sum += array[i][j];
        }
        printf("Sum of column #%d: %d\n", i,sum);
    }
        
    return 0;
}