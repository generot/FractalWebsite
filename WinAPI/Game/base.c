#include "basehead.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR CmdLine, int nCmdShow){
    WNDCLASS wClass = {0};

    wClass.hInstance = hInstance;
    wClass.lpszClassName = "WndClass";
    wClass.lpfnWndProc = &WProc;
    width = height = 700;
    myPos = (COORD){DEF_O, DEF_T};
    wd_hg = (COORD){20,20};

    RegisterClassA(&wClass);
    HWND wnd = CreateWindowA("WndClass", "My Game", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 
        CW_USEDEFAULT, width, height, NULL, NULL, hInstance, NULL);

    ShowWindow(wnd, nCmdShow);
    UpdateWindow(wnd);

    MSG toDispatch = {0};
    while(GetMessageA(&toDispatch, wnd, 0, 0)){
        TranslateMessage(&toDispatch);
        DispatchMessageA(&toDispatch);
    }

    return EXIT_SUCCESS;
}