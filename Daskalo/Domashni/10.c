//Идеята на програмата е, че за да избегнем проблеми със сравняването на малки и големи букви,
//превръщаме всички символи в един string в техните големи варианти(ако те вече са големи, си остават така)
//и ги сравняваме по тяхната стойност в ASCII таблицата, колкото по-малка е стойността на една буква, толкова
//по-нагоре е тя в азбуката(и ASCII таблицата). За да намерим главния еквивалент на една малка буква, намираме
//разликата 'а'-'А'. Така установяваме големината на интервала между една малка и една главна буква. И после
//от буквата, която искаме да направим главна, изваждаме тази разлика. Така получаваме същата буква, но главна.

#include <stdio.h>
#include <string.h>

#define MAXL 50

char toUpper(char arg){
    if(arg >= 'a' && arg <= 'z')
        return arg-('a'-'A');
    else return arg;
}

int main(){
    int counter, i;
    char str1[MAXL], str2[MAXL];

    fgets(str1, MAXL, stdin);
    fgets(str2, MAXL, stdin);

    size_t sz1 = strlen(str1), sz2 = strlen(str2);

    if(sz1 < sz2)
        counter = sz1;
    else counter = sz2;

    for(i = 0; i < counter; i++){
        if(toUpper(str1[i]) == toUpper(str2[i]))
            continue;
        else if(toUpper(str1[i]) < toUpper(str2[i])){
            printf("\n%s%s", str1, str2);
            break;
        }
        else {
            printf("\n%s%s", str2, str1);
            break;
        }
    }

    if(i == counter) printf("\n%s%s", str1, str2);
    return 0;
}