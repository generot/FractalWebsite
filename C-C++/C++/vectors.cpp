#include <iostream>
#include <vector>

using namespace std;

class Tower {
    int height, cost, power;
    public:
    Tower(int hg, int c, int pw){
        this->height = hg;
        this->cost = c;
        this->power = pw;
    }
    int *GetChars(){
        //Free allocated memory after usage
        int *m = (int*)calloc(3,sizeof(int));
        m[0] = this->height;
        m[1] = this->cost;
        m[2] = this->power;
        return m;
    }
};

int main(){
    vector<Tower> vT;
    int *chars;
    
    for(int i = 0; i < 4; i++){
        Tower tw = Tower(rand()%20, rand()%30, rand()%10);
        vT.push_back(tw);
    }

    for(Tower t : vT){
        chars = t.GetChars();
        for(int i = 0; i < 3; i++)
            cout << chars[i] << " ";
            
        cout << endl;
    }

    return EXIT_SUCCESS;
}