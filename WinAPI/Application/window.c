#include "head.h"

char *str, *wName = "Brainfuck Parser - IDE v0.1";
int _index = 0, posX = 20, posY = 30, w = 900, h = 900;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine ,int nCmdShow){
    str = calloc(MAXBUFF, sizeof(char));
    memset(str, ' ', MAXBUFF);
    str[MAXBUFF-1] = '\0';
    
    WNDCLASS wndClass = {0};

    wndClass.lpszClassName = "MyClass";
    wndClass.hInstance = hInstance;
    wndClass.lpfnWndProc = &Proc;
    wndClass.hIcon = (HICON)LoadImageA(NULL, "IDEIcon.ico", IMAGE_ICON, 100, 100, LR_LOADFROMFILE);

    FreeConsole();
    RegisterClassA(&wndClass);
    HWND wind = CreateWindowA("MyClass", wName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 
        CW_USEDEFAULT, w, h, NULL, NULL, hInstance, NULL);
    
    ShowWindow(wind, nCmdShow);
    UpdateWindow(wind);

    MSG msg = {0};
    while(GetMessageA(&msg, wind, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    free(str);
    return EXIT_SUCCESS;
}

LRESULT WINAPI Proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
    switch(msg){
    case WM_PAINT:{
        PAINTSTRUCT pst;
        HDC dc = BeginPaint(hwnd, &pst);
        HBRUSH br = (HBRUSH)(COLOR_BACKGROUND + 5);

        FillRect(dc, &pst.rcPaint, br);
        DrawTextA(dc, TEXT(str), strlen(str)+1, &pst.rcPaint, DT_LEFT | DT_TOP);

        EndPaint(hwnd, &pst);
        ReleaseDC(hwnd, dc);
        break;
    }
    case WM_DESTROY:{
        DestroyWindow(hwnd);
        free(str);
        exit(EXIT_SUCCESS);
    }
    case WM_CHAR:{
        if(!HandleSpecK(str, wp, &_index, &posY)){
            str[_index] = (char)wp;
            _index++;
        }
        
        TextOut(GetDC(hwnd), posX, posY, TEXT(str), strlen(str)+1);
        break;
    }
    default: break;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}