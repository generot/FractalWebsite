#include <stdio.h>
#include <string.h>

#define LN 20
int main(){
    char arr[LN] = {0};

    scanf("%19[^\n]s", arr);
    arr[LN-1] = '\0';

    for(int i = 0; i < strlen(arr); i++){
        if(arr[i] >= 'A' && arr[i] <= 'Z'){
            printf("%c", arr[i] + ('a'-'A'));
        } else if(arr[i] >= 'a' && arr[i] <= 'z'){
            printf("%c", arr[i] - ('a'-'A'));
        } else {
            printf("%c", arr[i]);
        }
    }
    return 0;
}