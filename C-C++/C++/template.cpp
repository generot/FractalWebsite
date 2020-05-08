#include <iostream>

using std::cout;

template<typename T>
T func(T a, T b){return (a<b?b:a);}

int main(){
    cout << func<int>(3,4);
    return 0;
}