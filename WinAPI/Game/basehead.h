//Useful comments:
//Main procedure: base.c
//Callback and other procedures: tools.c

#ifndef __BASE_H__
#define __BASE_H__

#if !defined(_WIN64) || !defined(__MINGW64__)
#error Compiler/OS not supported.
#endif

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define DEF_O 100
#define DEF_T 120

int width, height;
COORD myPos, oppPos, wd_hg;

#ifdef __cplusplus
extern "C" {
#endif

LRESULT WINAPI WProc(HWND hwnd, UINT message, WPARAM wordP, LPARAM longP);
void CheckInput(int key, int inc);
void DrawPlayer(HDC dc, COLORREF color, COORD pos, COORD wnh);

#ifdef __cplusplus
}
#endif

#endif