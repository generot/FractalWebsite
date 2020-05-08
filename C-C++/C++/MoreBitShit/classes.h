#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

#define ERR_MSG "Out of bounds"

using std::cout;
using std::cin;
using std::endl;

class bit_arr32 {
    private:
        uint32_t num, len;
    public:
        bit_arr32(uint32_t n);
        void SetBit(uint32_t st);
        void ClearBit(uint32_t pos);
        void Print();
};