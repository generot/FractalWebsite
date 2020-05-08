#include <stdio.h>
#include <windows.h>

int main(){
    for(int i = 0; i < 4; i++)
        MessageBoxA(NULL,"Hello","Message box",MB_YESNO);
    return EXIT_SUCCESS;
}