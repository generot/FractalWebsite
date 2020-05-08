#include <stdio.h>

void line(char a, char b, int c){
	for(int i = 1; i < c; i++){
		for(int j = 0; j < i; j++){
			printf("%c", a);
		}
		for(int j = 0; j < c-i-1; j++){
			printf("%c", b);
		}
		printf("\n");
	}
}

int main(){
	int l = 50;
	
	line('*', '-', l);
	return 0;
}