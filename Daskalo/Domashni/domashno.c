#include <stdio.h>
#include <string.h>

#define MAX 100

int main(){
    char c[MAX], d[MAX], msg1[] = "Yes", msg2[] = "No";

    scanf("%99[^\n]s", c);
    scanf("\n");
    scanf("%99[^\n]s", d);

    c[MAX-1] = d[MAX-1] = '\0';
    size_t len1 = strlen(c)+1, len2 = strlen(d)+1;

    if(len1 == len2){
        int i;
        for(i = 0; i < len1; i++){
            if(c[i] != d[i]){
                printf("%s",msg2);
                break;
            }
        }
        if(i == len1) printf("%s",msg1);
    } else printf("%s",msg2);

    return 0;
}