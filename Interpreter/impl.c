#include "utilities.h"

void Handle_BaseOp(char *mem, char *inp, int *memptr, int ind, bool deb){
    switch(inp[ind]){
    case '>': *memptr < INIT_MEM ? ++*memptr : Error(ERR_PTR); break;
    case '<': *memptr > 0 ? --*memptr : Error(ERR_PTR); break;
    case '+': mem[*memptr] < SCHAR_MAX ? mem[*memptr]++ : Error(ERR_SCHAR_BDRY, *memptr, memptr); break;
    case '-': mem[*memptr] > SCHAR_MIN ? mem[*memptr]-- : Error(ERR_SCHAR_BDRY, *memptr, memptr); break;
    case '.': deb ? printf("%d\n", mem[*memptr]) : printf("%c\n", mem[*memptr]); break;
    case ',': {scanf("\n");scanf("%c", &mem[*memptr]); break;}
    case '[': Handle_WhileOp(mem, inp, memptr, ind, deb); break;
    }
}

void Handle_WhileOp(char *mem, char *inp, int *memptr, int ind, bool toPass){
    int i;
    for(i = ind; i < strlen(inp); i++)
        if(inp[i] == ']')
            break;

    if(i != strlen(inp)){
        int currPos = *memptr;
        while(mem[currPos] > 1){
            for(int j = ind+1; j < i; j++)
                Handle_BaseOp(mem, inp, memptr, j, toPass);
            mem[currPos]--;
        }
    } else Error(ERR_SYNTX);
}

void Error(const char *msg, ...){
    va_list list;
    va_start(list, msg);

    vprintf(msg, list);
    exit(EXIT_FAILURE);
}