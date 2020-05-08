#include <stdio.h>

int main(){
    int x, y, sum = 0;

    printf("Enter the number of rows: ");
    scanf("%d",&x);
    printf("Enter the number of columns: ");
    scanf("%d",&y);

    int array[x][y];

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            scanf("%d", &array[i][j]);
        }
    }

    printf("\n");

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < x; i++){
        sum = 0;
        for(int j = 0; j < y; j++){
            sum += array[i][j];
        }
        printf("Sum of row #%d: %d\n", i,sum);
    }

    for(int i = 0; i < y; i++){
        sum = 0;
        for(int j = 0; j < x; j++){
            sum += array[j][i];
        }
        printf("Sum of column #%d: %d\n", i,sum);
    }
        
    return 0;
}