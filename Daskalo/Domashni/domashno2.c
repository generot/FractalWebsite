#include <stdio.h>

#define BOUND 1000
void Primecheck(int toCheck){
	int divisors = 0;
	if(toCheck >= 0 && toCheck <= BOUND){
		for(int i = 1; i <= toCheck; i++){
			if(!(toCheck % i)) divisors++;
		}

		if(divisors == 2) printf("Prime\n");
		else printf("Composite\n");

	} else printf("Out of bounds."); 
}

int main(){
	int inp;
	scanf("%d", &inp);

	Primecheck(inp);
	return 0;
}