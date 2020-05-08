#include <stdio.h>
#include <string.h>

#define LEN 50

int main(){
    int i;
    char a[LEN];

    scanf("%s", a);
    a[LEN-1] = '\0';

    size_t len = strlen(a);

    for(i = 0; i < len/2; i++){
        if(a[i] != a[len-i-1])
            break;
    }

    if(i == len/2)
        printf("The word is a palindrome");
    else printf("The word is NOT a palindrome");

    return 0;
}