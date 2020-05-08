#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv){
    FILE *f = fopen(argv[1],"r");

    fseek(f,0,SEEK_END);
    printf("%li bytes", ftell(f));

    fclose(f);
}