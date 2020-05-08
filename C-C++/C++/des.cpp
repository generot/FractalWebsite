#include <iostream>

using std::cout;
typedef float triang;
typedef triang triang_3[3];

int main(){
    triang_3 tr = {0};
    tr[0] = 23;
    cout << tr[0] << " " << tr[1] << " " << tr[2];
    return 0;
}