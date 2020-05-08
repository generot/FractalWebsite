#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct student{
    unsigned int age;
    char name[30];
} student;

int main(){
    student *students;
    int amount = 0, i;

    scanf("%d",&amount);
    students = malloc(amount*sizeof(student));
    for(i = -1; ++i < amount;){
        scanf("%d %s",&students[i].age,&students[i].name);
    }
    for(int j = -1; ++j < amount;){
        printf("Student #%d - %s - %d years old\n",j+1,students[j].name,students[j].age);
    }
    getch();
}