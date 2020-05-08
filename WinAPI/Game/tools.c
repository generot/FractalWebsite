#include "basehead.h"

LRESULT WINAPI WProc(HWND hwnd, UINT message, WPARAM wordP, LPARAM longP){
    COLORREF color = RGB(255, 0, 0);

    switch(message){
    case WM_PAINT: {
        PAINTSTRUCT paint;
        HDC dc = BeginPaint(hwnd, &paint);

        FillRect(dc, &paint.rcPaint, (HBRUSH)(COLOR_BACKGROUND + 10));
        DrawPlayer(GetWindowDC(hwnd), color, myPos, wd_hg);
        
        EndPaint(hwnd, &paint);
        ReleaseDC(hwnd, dc);
        break;
    }
    case WM_DESTROY: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
        exit(EXIT_SUCCESS);
        break;
    }
    case WM_CHAR: {
        //COORD pos = myPos, newPos;
        RECT rc = {0};
        HBRUSH brush = CreatePatternBrush((HBITMAP)
            LoadImageA(NULL, "BestMethodYet.bmp", IMAGE_BITMAP, wd_hg.X, wd_hg.Y, LR_LOADFROMFILE));
        //DrawPlayer(GetWindowDC(hwnd), color, myPos, wd_hg);
        SetRect(&rc, myPos.X, myPos.Y, myPos.X + wd_hg.X, myPos.Y + wd_hg.Y);
        FillRect(GetWindowDC(hwnd), &rc, brush);
        CheckInput(wordP, 10);
        //newPos = myPos;

        // Sleep(10);
        // if(newPos.X != pos.X || newPos.Y != pos.Y)
        //     DrawPlayer(GetWindowDC(hwnd), RGB(0,0,0), pos, wd_hg);
        break;
    }
    default: return DefWindowProc(hwnd, message, wordP, longP);
    }
    return 0;
}

void CheckInput(int key, int inc){
    switch(key){
    case 'w':
        myPos.Y-=inc;
        break;
    case 'a':
        myPos.X-=inc;
        break;
    case 's':
        myPos.Y+=inc;
        break;
    case 'd':
        myPos.X+=inc;
        break;
    default: break;
    }
}

void DrawPlayer(HDC dc, COLORREF color, COORD pos, COORD wnh){
    for(int i = pos.Y; i < pos.Y + wnh.Y; i++){
        for(int j = pos.X; j < pos.X + wnh.X; j++){
            SetPixelV(dc, j, i, color);
        }
    }
}