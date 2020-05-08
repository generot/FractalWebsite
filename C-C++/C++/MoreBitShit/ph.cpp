#include "classes.h"

bit_arr32::bit_arr32(uint32_t n){
    this->num = n;
    this->len = 31;
}

void bit_arr32::SetBit(uint32_t st){
    if(st <= this->len) this->num |= (1<<st);
    else cout << ERR_MSG << endl;
}

void bit_arr32::ClearBit(uint32_t pos){
    if(pos <= this->len) this->num &= ~(1<<pos);
    else cout << ERR_MSG << endl;
    
}

void bit_arr32::Print(){
    for(int i = this->len; i >= 0; i--){
        if(this->num & (1<<i))
            cout << "1";
        else cout << "0";
    }
    cout << "\n";
}