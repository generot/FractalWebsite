#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <unistd.h>

#define MAX 6
#define _UTF_8_ 0x00020000

int main(int argc, char**argv){
    FILE *stream = fopen(argv[1],"rb"), *toPaste;
    char *extension = calloc(MAX,sizeof(char)), *str = argv[1];

    size_t sz_stream = strlen(str);
    
    //This piece of code gets the target file's extension for further use.
    for(int i = 0; i < sz_stream; i++){
        if(str[i] == '.'){
            for(int j = i; j < sz_stream; j++){
                extension[j-i] = str[j];
            }
            extension[MAX-1] = '\0';
            break;
        }
    }

    char *fName = "NewFile";
    size_t sz_ap = strlen(fName)+MAX;

    char *appendedStr = calloc(sz_ap,sizeof(char));

    strncpy(appendedStr,fName,strlen(fName));
    strcat(appendedStr,extension);
    appendedStr[sz_ap-1] = '\0';

    toPaste = fopen(appendedStr,"wb");

    _setmode(fileno(stream), _UTF_8_);
    _setmode(fileno(toPaste), _UTF_8_);

    while(!feof(stream)){
        fwprintf(toPaste,L"%lc",(wchar_t)fgetwc(stream));
    }

    fclose(stream);
    fclose(toPaste);
    free(extension);

    return 0;
}