#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f = fopen("Hello.txt","w");
    fprintf(f,"Hello");
    fclose(f);
}