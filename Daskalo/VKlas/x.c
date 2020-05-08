#include <stdio.h>

void Square(char a, char b, int c);

int main(){
    int num;
    scanf("%d", &num);
    num += 2;

    for(int i = 0; i < num; i++){
        if(i == 0 || i == num-1){
            Square('.', 0, num);
            printf("\n");
        } else {
            Square('V', '-',num);
            printf("\n");
        }
    }
    return 0;
}

void Square(char a, char b, int c){
    char k;
    k = b != 0 ? b : a;

    for(int i = 0; i < c; i++){
        if(i == 0 || i == c-1)
            printf("%c ", k);
        else printf("%c ", a);
    }
}