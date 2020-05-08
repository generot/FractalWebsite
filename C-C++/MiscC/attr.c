#include <stdio.h>
#include <windows.h>

int main(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0; i < 15; i++){
        SetConsoleTextAttribute(h, i);
        printf("%d - a\n", i);
    }
    free(h);
    getch();
    return 0;
}