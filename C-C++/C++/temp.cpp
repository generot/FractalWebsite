#include <iostream>

using namespace std;

template <int a>
struct Return {
    static const int ret = 3*Return<a-1>::ret;
};

template <> 
struct Return<0> {
    static const int ret = 1;
};

template <typename A>
class myClass {
private:
    A a, b;
public:
    static int smth;

    myClass(A a1, A b1) {a = a1; b = b1; smth++;}
    A sum(){
        return a+b;
    }
};

template <typename B>
int myClass<B>::smth = 0;

int main(){

    myClass<int> first(3, 4);
    myClass<int> third(5, 10);
    myClass<float> second(2.4, 8.8);

    cout << first.sum() << " " << sizeof(first) << " " << myClass<int>::smth << endl;
    cout << third.sum() << " " << myClass<int>::smth << endl;
    cout << second.sum() << " " << myClass<float>::smth << endl;

    cout << Return<4>::ret << endl;

    return EXIT_SUCCESS;
}