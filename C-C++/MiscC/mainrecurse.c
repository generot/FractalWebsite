#include <stdio.h>

int f = 0, g = 1, k = 9;

int main(a, d){
    printf("%d\n", f);
    d = f+g;
    f = g;
    g = d;
    k--;
    a ? main(k, d):0;
}