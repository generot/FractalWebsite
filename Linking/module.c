#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// void Swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
//void __MIDL_DECLSPEC_DLLEXPORT Swap(int *a, int *b);
int main(){
    HINSTANCE lib = LoadLibraryA("mod");
    void (*swap)(int*,int*) = (void*)GetProcAddress(lib, "Swap");
    int a, b;
    a = 4;
    b = 17;
    swap(&a,&b);

    printf("a-%d ; b-%d", a, b);
    FreeLibrary(lib);
    return 0;
}