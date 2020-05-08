#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX_EXT 7
#define MAX_NAME 20

LPSTR get_extension(LPCSTR path){
    size_t len = strlen(path)+1;
    LPSTR ret = malloc(MAX_EXT*sizeof(char));

    for(int i = 0; i < len; i++){
        if(path[i] == '.'){
            for(int j = i, cnt = 0; j < len; j++, cnt++)
                ret[cnt] = path[j];
            break;
        }
    }
    return ret;
}

int main(){
    char filePath[MAX_PATH] = {0}, copyPath[MAX_PATH] = {0};
    LPSTR name = malloc(MAX_NAME*sizeof(char));
    
    printf("Enter path: ");
    scanf("%s", filePath);
    filePath[MAX_PATH-1] = '\0';

    LPSTR ext = get_extension(filePath);

    HANDLE file = CreateFileA(filePath, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 
        NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL),
    copy = NULL;

    DWORD flSize = GetFileSize(file, NULL);
    LPVOID mem = VirtualAlloc(NULL, flSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    ReadFile(file, mem, flSize, NULL, NULL);

    printf("Enter the name of the copy: ");
    scanf("%s", name);
    name[MAX_NAME-1] = '\0';

    snprintf(copyPath, MAX_PATH, "%s%s", name, ext);
    copy = CreateFileA(copyPath, GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, 
        NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    WriteFile(copy, mem, flSize, NULL, NULL);

    free(name);
    free(ext);
    VirtualFree(mem, 0, MEM_RELEASE);
    CloseHandle(file);
    CloseHandle(copy);
    return EXIT_SUCCESS;
}

