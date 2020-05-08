#include "smth.h"

int main(){
    BasicArithmetic bs = BasicArithmetic();
    std::cout << "The sum of 5,3,9 and 2 is: "<< bs.add(4,5,3,9,2) << std::endl;
    std::cout << "The product of 3 and 6 is: "<< bs.mult(2,3,6) << std::endl;
    bs.~BasicArithmetic();
    return EXIT_SUCCESS;
}