#ifdef __cplusplus
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>

class BasicArithmetic {
    public:
    BasicArithmetic();
    ~BasicArithmetic();
    int add(int elms, ...);
    int mult(int elms, ...);
};

#endif