#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void movensleep(SHORT *crd, int duration, int dir);

#define CHECK_KEY(x) if(GetAsyncKeyState(x))
#define CHECK_ESC if(GetAsyncKeyState(VK_ESCAPE))exit(EXIT_SUCCESS)

int main(){
    HANDLE consHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD plC = {0,0}, screenD;
    
    DWORD bin, num = 3;
    WORD snake_col = 20, black = 1;

    BOOL WINAPI (*ConsoleSize)(HANDLE, DWORD, PCOORD) = GetProcAddress(GetModuleHandleA("Kernel32"),
        "SetConsoleDisplayMode");

    ConsoleSize(consHandle, 1, &screenD);

    //Equivalent to a game update method
    while(TRUE){
        COORD prevC = plC;

        //Checking for user input
        CHECK_KEY(VK_NUMPAD6)
            movensleep(&plC.X, 20, 1);
        CHECK_KEY(VK_NUMPAD8)
            movensleep(&plC.Y, 20, -1);
        CHECK_KEY(VK_NUMPAD4)
            movensleep(&plC.X, 20, -1);
        CHECK_KEY(VK_NUMPAD5)
            movensleep(&plC.Y, 20, 1);

        CHECK_ESC;

        WriteConsoleOutputAttribute(consHandle, &snake_col, num, plC, &bin);
        if(plC.X != prevC.X || plC.Y != prevC.Y)
            WriteConsoleOutputAttribute(consHandle, &black, (DWORD)1, prevC, &bin);
    }

    free(consHandle);
    return EXIT_SUCCESS;
}

void movensleep(SHORT *crd, int duration, int dir){
    *crd+=dir;
    Sleep(duration);
}