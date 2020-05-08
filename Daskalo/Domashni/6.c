#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int toCheck[n], checked = 0;

    for(int i = 0; i < n; i++)
        scanf("%d",&toCheck[i]);

    for(int j = 0; j < n; j++){
        if(toCheck[j] == toCheck[n-j-1]) //Проверяваме дали текущия елемент и неговия симетричен елем. са равни.
            checked++;
        if(j == (n/2)) //Ако стигнем до средата, излизаме от цикъла, защото вече сме проверили всички елементи.
            break;
    }
    if(checked == (n/2)+1) printf("YES"); //Ако броя на верни равенства е равен на броя на елементите в 1/2 от масива,
    else printf("NO");                   //значи масива е симетричен.
    
    return 0;
}