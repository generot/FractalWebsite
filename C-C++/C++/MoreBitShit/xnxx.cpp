#include "classes.h"

int main(){
    std::vector<bit_arr32> vBits;
    int amount;

    cout << "Enter the desired amount of bit arrays: " << endl;
    cin >> amount;

    cout << "Enter the numbers that will be represented by the bit arrays: " << endl;
    for(int i = 0; i < amount; i++){
        uint32_t elem;
        cin >> elem;
        bit_arr32 currentArray(elem);
        char inp, *ans = new char[16];
        ans[15] = '\0';

        cout << "Do you wish to make any changes to the bit arrays?('y' or 'n'): ";
        s:cin >> inp;

        if(inp == 'y'){
            uint32_t pos;
            cout << "Do you wish to clear/set a bit('clear' or 'set'): ";
            k:cin >> ans;

            if(strcmp(ans, "clear") == 0){
                cout << "Enter a position: ";
                cin >> pos;
                currentArray.ClearBit(pos);
            } else if(strcmp(ans, "set") == 0){
                cout << "Enter a position: ";
                cin >> pos;
                currentArray.SetBit(pos);
            } else {cout << "Invalid answer. Try again: "; goto k;}
            vBits.push_back(currentArray);
        } 
        else if(inp == 'n')
            vBits.push_back(currentArray);
        else {cout << "Invalid answer. Try again: "; goto s;}

        delete[] ans;
    }


    for(bit_arr32 ba : vBits)
        ba.Print();

    return 0;
}