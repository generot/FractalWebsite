#include <stdio.h>
#include <string.h>

#define MAX 10
int main(){
    int cnt, sum = 0;
    char str1[MAX], str2[MAX];

    scanf("%s%s",str1,str2);
    str1[MAX-1] = str2[MAX-1] = '\0';

    if((cnt = strlen(str1)) != strlen(str2))
        return 1;

    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < cnt; j++){
            if(str1[i] == str2[j])
                str1[i] = str2[j] = 0; // abcd - bgfc => a00d - 0gf0
        }
    }

    for(int i = 0; i < cnt; i++){
        for(int j = i+1; j < cnt; j++){
            if(str1[i] == str1[j])
                str1[j] = 0; // 0aaa - 0a00
            if(str2[i] == str2[j])
                str2[j] = 0;
        }
    }

    for(int i = 0; i < cnt; i++){
        if(str1[i] != 0){
            printf("%c ",str1[i]);
            sum += str1[i];
        }
        if(str2[i] != 0){
            printf("%c ",str2[i]);
            sum += str2[i];
        }
    }
    printf("\nThe sum is: %d", sum);
    
    return 0;
}