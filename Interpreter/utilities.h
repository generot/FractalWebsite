#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <limits.h>
#include <string.h>
#include <conio.h>

//Stack memory and input buffer definitions
#define INIT_MEM 100
#define BUFF_LEN 1024

//Error messages
#define ERR_SCHAR_BDRY "Error: Memory out of bounds at address: %d (0x%X)"
#define ERR_PTR "Error: Stack pointer out of bounds. Segmentation fault."
#define ERR_SYNTX "Syntax error: Matching pair for '[' not found."

//If we include this header in a .cpp(C++) file, we ignore the enumeration
//since C++ has a built in boolean variable type
#ifndef __cplusplus
typedef enum Bool {false, true} bool;
#endif

//Allowing compatibility with C++ /by disabling name mangling/
#ifdef __cplusplus
extern "C" {
#endif //_cplusplus

void Handle_BaseOp(char *mem, char *inp, int *memptr, int ind, bool deb);
void Handle_WhileOp(char *mem, char *inp, int *memptr, int ind, bool toPass);
void Error(const char *msg, ...);

#ifdef __cplusplus
}
#endif //_cplusplus

#endif //UTILS_H_