#include <stdio.h>
#include <stdint.h>

int divi(int a, int b){return a/b;}
double divf(double a, double b){return a/b;}

#define DIVISION(a, b) _Generic((a),    \
        int: divi,                      \
        double: divf                    \
)(a, b)

#define A(a) _Generic((a),       \
        char: "This is a char",  \
        int: "This is an int"    \
)

int main(){
    printf("%d", DIVISION(10, 5));
    printf("\n%s\n%s", A('a'), A(19));
    return 0;
}