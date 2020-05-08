#include <iostream>

using namespace std;

class Base {

public:
    int add(int x, int y){
        return x + y;
    }
    int sub(int x, int y){
        return x - y;
    }
};

class Derived : public Base{
public:
    int mult(int a, int b){
        return a * b;
    }
};

int main(){
    Derived cl;
    int a = 3, b = 4;

    cout << cl.add(a,b) << '\n' << cl.sub(a,b) << '\n' << cl.mult(a,b) << endl;
    return 0;
}