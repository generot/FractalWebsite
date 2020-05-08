#include <iostream>
namespace mns {
    class Apple {
        int weight;

        public:
        void SetWeight(){
            std::cin >> this->weight;
        }
        int GetWeight(){
            return this->weight;
        }
    };
    
};

int main(){
    mns::Apple myApple;
    myApple.SetWeight();

    std::cout << myApple.GetWeight() << std::endl;
}