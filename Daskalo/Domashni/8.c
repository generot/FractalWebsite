#include <stdio.h>

int main(){
    char arr[] = "ABCDEFGH";
    for(int i = 8; i > 0; i--){
        for(int j = 0; j < sizeof(arr)-1; j++){
            printf("%c%d ", arr[j], i);
        }
        printf("\n");
    }
    // for(int j = 8; j > 0; j--){
    //     for(char i = 'A'; i < 'I'; i++){
    //         printf("%c%d ", i, j);
    //     }
    //     printf("\n");
    // }
    return 0;
}
//main(i,j){for(i=9;i-->1;){for(j=64;j++<72;){printf("%c%d ",j,i);}puts("");}}