#include "head.h"

int main(){
    Pr(A);
    
    HINSTANCE lib = LoadLibraryA("Kernel32");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD newC;

    BOOL WINAPI (*ConsMode)(HANDLE,BOOL,PCOORD) = GetProcAddress(lib,"SetConsoleDisplayMode");
    ConsMode(h,1,&newC);

    getch();
    FreeLibrary(lib);
}