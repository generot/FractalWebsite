#include <stdio.h>
#include <windows.h>

int main(){
    SetConsoleTitleA("Target");
    while(TRUE){
        printf("Hello\n");
        Sleep(1000);
    }
}

