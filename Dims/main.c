#include "head.h"

int main(){
    HANDLE *con = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD w = 20;
    DWORD dw;
    COORD host;

    HINSTANCE lib = LoadLibraryA("Kernel32");
    BOOL WINAPI (*Con)(HANDLE,DWORD,PCOORD) = GetProcAddress(lib,"SetConsoleDisplayMode");

    int x, y;
    x = y = 0;

    Con(con,1,&host);

    while(1){ 
        COORD pos = {x,y};
        if(GetAsyncKeyState(VK_NUMPAD6)){
            x++;
            Sleep(20);
        }
        if(GetAsyncKeyState(VK_NUMPAD4)){
            x--;
            Sleep(20);
        }
        if(GetAsyncKeyState(VK_NUMPAD8)){
            y--;
            Sleep(20);
        }
        if(GetAsyncKeyState(VK_NUMPAD5)){
            y++;
            Sleep(20);
        }
        WriteConsoleOutputAttribute(con,&w,1,pos,&dw);
    }

    getch();
    FreeLibrary(lib);
    return EXIT_SUCCESS;
}