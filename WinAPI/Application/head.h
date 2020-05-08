#ifndef _HEAD_H_
#define _HEAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAXBUFF 4096

#define C_BACKSPACE 8
#define C_TAB '\t'
#define C_RETURN 13

typedef enum Bool {false, true} bool;

LRESULT WINAPI Proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
bool HandleSpecK(char *str, char key, int *ind, int *posY);

#endif