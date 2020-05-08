#include <stdio.h>
#include <stdlib.h>

typedef int (*add)(int,int);
int Add(int a, int b);
void PrintNum(int a, add k);