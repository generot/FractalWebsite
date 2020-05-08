#include <windows.h>
#include <stdio.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
    if(fdwReason == DLL_PROCESS_ATTACH)
        MessageBoxA(NULL, "You have been hacked!", "Dll", MB_OK);
    return TRUE;
}