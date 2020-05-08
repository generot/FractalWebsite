//This program has a memory leak which has NO FUCKING REASONABLE SOLUTION(I don't want to free()
//the strings at the end of the entry point(main()))
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 30

typedef struct obj{
    char *objName;
    void (*print)(struct obj self);
} obj_t;

void Print(struct obj self){
    printf("%s\n", self.objName);
}

#if defined(_WIN64)
#define _construct_(Obj) ({Obj.objName = malloc(MAX_CHARS);Obj.print = &Print;})
#endif

obj_t example; 
obj_t example2;

__attribute__((constructor)) void Init_Object(){
    _construct_(example);
    _construct_(example2);
    printf("Objects initialized\n");
}

int main(){
    example.objName = "My Class";
    example.print(example);

    example2.objName = "Second Class";
    example2.print(example2);

    return EXIT_SUCCESS;
}