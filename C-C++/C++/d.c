#include <stdio.h>

typedef int triang;
typedef triang triang_3[3];

int main(){
    triang_3 tr = {0};
    tr[0] = 23;
    printf("%d %d %d", tr[0], tr[1], tr[2]);
    return 0;
}