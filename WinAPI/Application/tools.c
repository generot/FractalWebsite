#include "head.h"

bool HandleSpecK(char *str, char key, int *ind, int *posY){
    switch(key){
    case C_BACKSPACE:{
        str[(*ind)-1] = ' ';
        --*ind;
        break;
    }
    case C_RETURN:{
        memset(str, ' ', MAXBUFF);
        str[MAXBUFF-1] = '\0';
        (*posY) += 20;
        (*ind) = 0;
        break;
    }
    case C_TAB:{
        for(int i = 1; i < 5; i++)
            str[++*ind] = ' ';
        break;
    }
    default: return false;
    }
    return true;
}
