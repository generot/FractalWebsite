#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_BUFF 40
#define MAX_EXT 6

typedef struct sub_folder {
    char *name, *fullPath;
} folder;

void init_folder(folder *ref, char *primDir, char *name);
void add_contents(folder *ref, char *contDir, char *newName);
void destroy_folder(folder *ref);
char *get_ext(char *dir);

int main(){
    char *primaryDir = malloc(MAX_BUFF*sizeof(char));
    int amount;

    printf("Name of the main folder: ");
    scanf("%s", primaryDir);
    primaryDir[MAX_BUFF-1] = '\0';

    CreateDirectoryA(primaryDir, NULL);
    printf("\nNumber of subfoldders: ");
    scanf("%d", &amount);

    folder instances[amount];
    for(int i = 0; i < amount; i++){
        int amn;
        char *currName = calloc(MAX_BUFF,sizeof(char)), *filePath = calloc(MAX_PATH, sizeof(char));

        printf("\nName of subfolder #%d: ", i+1);
        scanf("%s", currName);
        currName[MAX_BUFF-1] = '\0';

        init_folder(&instances[i], primaryDir, currName);

        printf("\nNumber of files in subfolder #%d: ", i+1);
        scanf("%d",&amn);

        for(int j = 0; j < amn; j++){
            char *ext = NULL, *nameRef = malloc(MAX_BUFF*sizeof(char));
            strncpy(nameRef, instances[i].name, strlen(instances[i].name)+1);
            memset(filePath,0,strlen(filePath)+1);

            printf("\nPath to file #%d: ", j+1);
            scanf("%s", filePath);
            filePath[MAX_PATH-1] = '\0';
            ext = get_ext(filePath);

            strncat(nameRef, ext, strlen(ext)+1);
            add_contents(&instances[i], filePath, nameRef);
            
            free(ext);
            free(nameRef);
        }

        free(currName);
        free(filePath);
    }
    
    free(primaryDir);
    for(int j = 0; j < amount; j++)
        destroy_folder(&instances[j]);

    return EXIT_SUCCESS;
}

void init_folder(folder *ref, char *primDir, char *name){
    LPSTR dir = malloc(MAX_PATH*sizeof(CHAR));

    GetCurrentDirectoryA(MAX_PATH, dir);

    strncat(dir, "\\", sizeof "\\");
    strncat(dir, primDir, strlen(primDir)+1);
    strncat(dir, "\\", sizeof "\\");
    strncat(dir, name, strlen(name)+1);

    ref->name = name;
    ref->fullPath = dir;
    CreateDirectoryA(ref->fullPath, NULL);
}

void add_contents(folder *ref, char *contDir, char *newName){
    char *dir = malloc(MAX_PATH*sizeof(char));

    strncpy(dir, ref->fullPath, strlen(ref->fullPath)+1);
    strncat(dir, "\\", sizeof "\\");
    strncat(dir, newName, strlen(newName)+1);

    CopyFileA(contDir, dir, FALSE);
    free(dir);
}

char *get_ext(char *dir){
    char *toReturn = malloc(MAX_EXT*sizeof(char));
    int cnt = 0;

    for(int i = 0; i < strlen(dir)+1; i++){
        if(dir[i] == '.'){
            for(int j = i; j < strlen(dir)+1; j++){
                toReturn[cnt] = dir[j];
                cnt++;
            }
        }
    }

    toReturn[MAX_EXT-1] = '\0';
    return toReturn;
}

void destroy_folder(folder *ref){
    free(ref->fullPath);
    free(ref->name);
}