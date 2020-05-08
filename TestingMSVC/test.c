#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define P(x) (x*x)
int main(){
    int x = 30, y = 30, scl = 10;
    for(int i = -y; i < y; i++){
        for(int j = -x; j < x; j++){
            double a = (double)j/scl, b = (double)i/scl;
            const double cA = a, cB = b;
            int iter, max = 100;
            for(iter = 0; iter < max; iter++){
                double sqA = P(a)-P(b), sqB = 2*a*b;
                a = cA + sqA;
                b = cB + sqB;
                if(abs(a+b)>4)
                    break;
            }
            if(iter == max)
                printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    getch();
    return 0;
}