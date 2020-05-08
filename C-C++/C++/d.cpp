#include <iostream>
class Base {
    private:
    std::string toPrint;
    bool state;

    public:
    Base(std::string msg, bool st){
        this->toPrint = msg;
        this->state = st;
        std::cout << "Class initialized" << std::endl;
    }
    void print(){
        std::cout << this->toPrint << std::endl;
        if(this->state)
            std::cout << "true";
        else std::cout << "false";
    }
};

int main(){
    Base base("My message",true);
    base.print();
    return 0;
}