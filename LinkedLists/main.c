#include "head.h"

int main(){
    int length = 9;
    list *end = malloc(sizeof(list)); 
    end->num = 3;
    end->nextList = NULL;

    for(int i = 0; i < length; i++){
        list *t = malloc(sizeof(list));
        t->nextList = end;
        t->num = rand()%20;
        end = t;
    }

    for(list *j = end; j != NULL; j = j->nextList){
        printf("%d - ", j->num);
    }
    
    free(end);
}