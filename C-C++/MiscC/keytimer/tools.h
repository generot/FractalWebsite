#ifndef __TOOLS_H
#define __TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX_CHARS 16
#define WORDS_IN_DICT 40

char **dict(FILE *stream, size_t size);
void FreeAllocatedMemory(char **ptr, size_t len);

#endif