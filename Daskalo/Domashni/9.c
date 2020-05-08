#include <stdio.h>

int Power(int num, int pow){
    int res = 1;
    for(int i = 0; i < pow; i++)
        res *= num;

    return res;
}

int main(){
    int length, res = 0;
    scanf("%d", &length);

    char numstr[length+1];

    scanf("%s", numstr);
    numstr[length] = '\0';

    for(int i = 0; i < length; i++){
        if(numstr[i] < '0' || numstr[i] > '9')
            return 1;
    }

    for(int i = 0; i < length; i++){
        for(char j = '0', k = 0; j <= '9'; j++, k++){
            if(numstr[i] == j){
                res += k*Power(10,length-i-1); //1*100 + 2*10 + 3*10^0 = 123
            }
        }
    }

    printf("The integer value is: %d", res);
    return 0;
}