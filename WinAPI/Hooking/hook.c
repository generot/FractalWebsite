#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include <windows.h>
#include <tlhelp32.h>

BOOL ObtainProc(PPROCESSENTRY32W entry, LPWSTR exe_name){
    entry->dwSize = sizeof(PROCESSENTRY32W);

    HANDLE hand = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 1);
    Process32FirstW(hand, entry);
    if(wcscmp(entry->szExeFile, exe_name) == 0){
        CloseHandle(hand);
        return TRUE;
    }
    else {
        while(Process32NextW(hand, entry))
            if(wcscmp(entry->szExeFile, exe_name) == 0){
                CloseHandle(hand);
                return TRUE;
            }
    }
    CloseHandle(hand);
    return FALSE;
}

void err(BOOL val, LPSTR msg, LPSTR msg2){
    if(val){
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    } else printf("%s\n", msg2);
}

int main(){
    PROCESSENTRY32W entry;
    
    err(!ObtainProc(&entry, L"a.exe"), "Process cannot be obtained.", "Process obtained.");
    PCHAR str = "C:\\Users\\anoma\\Desktop\\MSVC-Projects\\WinAPI\\Hooking\\module.dll";

    HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
    if(proc == INVALID_HANDLE_VALUE){
        printf("Process cannot be opened.\n");
        exit(EXIT_FAILURE);
    } else printf("Process opened.\n");

    LPTHREAD_START_ROUTINE proC = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32"), "LoadLibraryA");

    LPVOID addr = VirtualAllocEx(proc, NULL, strlen(str)+1, MEM_COMMIT, PAGE_READWRITE);
    if(addr == NULL){
        printf("Memory could not be allocated.\n");
        exit(EXIT_FAILURE);
    } else printf("Memory allocated.\n");

    WriteProcessMemory(proc, (LPVOID)addr, (LPCVOID)str, strlen(str)+1, NULL);
    HANDLE rThread = CreateRemoteThread(proc, NULL, 0, proC, addr, 0, NULL);

    WaitForSingleObject(rThread, INFINITE);

    printf("Address: %p", addr);
    getch();

    VirtualFreeEx(proc, addr, (DWORD)strlen(str)+1, MEM_RELEASE);
    CloseHandle(proc);
    return EXIT_SUCCESS;
}