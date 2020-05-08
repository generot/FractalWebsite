#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include <fcntl.h>

#ifndef _O_U16TEXT
#define _O_U16TEXT 0x020000
#endif


int main(){
    printf("%d\n",_O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wchar_t *str = L"♠";
    wprintf(L"%ls",str);

    return 0;
}