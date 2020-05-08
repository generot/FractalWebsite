#include <stdio.h>
#include <stdlib.h>

void append(char**s);
int main(){
    char *s = malloc(10*sizeof(char));
    
    append(&s);
    printf("%s",s);
    return 0;
}
void append(char**s){
    *s = "Hello\0";
}