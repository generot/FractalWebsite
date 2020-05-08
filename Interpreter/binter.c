//The Brainfuck Interpreter is (hypothetically)completely C++ compliant,
//meaning that now, the source code can be compiled by a C++ compiler without causing
//undefined behaviour or triggering warnings/errors. Further testing would be done to
//completely determine wether the source code is, without a doubt, absolutely C++ compliant.  
#include "utilities.h"

int main(int argc, char **argv){
    char *mem = (char*)calloc(INIT_MEM, sizeof(char)), *input = (char*)malloc(BUFF_LEN*sizeof(char));
    int ptr = 0;

    bool inDebug = false;

    if(argc > 1)
        if(atoi(argv[1]))
            inDebug = true;

    fgets(input, BUFF_LEN, stdin);
    input[strlen(input)] = '\0';

    for(int i = 0; i < strlen(input); i++)
        Handle_BaseOp(mem, input, &ptr, i, inDebug);

    getch();
    
    free(input);
    free(mem);
    return EXIT_SUCCESS;
}
