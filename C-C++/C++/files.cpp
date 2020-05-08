#include <iostream>
#include <fstream>

using namespace std;
int main(){
    ifstream file;
    file.open("f.cpp", ios::in);
    
    while(!file.eof()){
        char c;
        file.read(&c, 1);
        cout << c;
    }
    
    file.close();
    cin.get();
    return 0;
}