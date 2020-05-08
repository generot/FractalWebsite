#include "smth.h"

BasicArithmetic::BasicArithmetic(){
    std::cout << "Class initialized" << std::endl;
}

BasicArithmetic::~BasicArithmetic(){
    std::cout << "Class destroyed" << std::endl;
}

int BasicArithmetic::add(int elms, ...){
    va_list list;
    int sum = 0;

    va_start(list,elms);
    for(int i = 0; i < elms; i++)
        sum += va_arg(list,int);

    va_end(list);
    return sum;
}

int BasicArithmetic::mult(int elms, ...){
    va_list list;
    int mlt = 1;

    va_start(list,elms);
    for(int i = 0; i < elms; i++)
        mlt *= va_arg(list,int);

    va_end(list);
    return mlt;
}