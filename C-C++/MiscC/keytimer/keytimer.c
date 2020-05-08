#include "tools.h"

int main(){
    FILE *dictionary = fopen("dictionary.txt","r");
    if(dictionary == NULL){
        perror("dictionary.txt not found");
        exit(EXIT_FAILURE);
    }

    HANDLE consHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD red = 12;

    int max_words = 0;
    l:printf("Enter the desired length of your exercise(in words): ");
    scanf("%d", &max_words);
    if(max_words > WORDS_IN_DICT)
        goto l;

    char *input = malloc(MAX_CHARS+10*sizeof(char)), **diction = dict(dictionary, WORDS_IN_DICT);

    clock_t beginning, end;
    beginning = clock();

    int diff = (float)(WORDS_IN_DICT - max_words)/(rand()%max_words+1) + 1;

    srand(time(NULL));
    for(int i = 0; i < max_words; i++){
        int index = (rand()%max_words)+(rand()%2)*diff;

        fprintf(stdout, "%s\n", diction[index]);
        p:scanf("%s",input);
        input[MAX_CHARS+9] = '\0';

        if(strcmp(diction[index], input) != 0){
            SetConsoleTextAttribute(consHandle, red);
            fprintf(stdout, "Incorrect. Enter again:\n");
            SetConsoleTextAttribute(consHandle, 7);
            goto p;
        }
    }

    end = clock();

    double elapsedTime = ((double)end - (double)beginning) / CLOCKS_PER_SEC;
    fprintf(stdout, "Elapsed time: %.2lf seconds\nAverage: %.2lf seconds every word", 
        elapsedTime, elapsedTime/max_words);

    getch();

    fclose(dictionary);
    free(input);
    free(consHandle);
    FreeAllocatedMemory(diction, WORDS_IN_DICT);
    return EXIT_SUCCESS;
}

char **dict(FILE *stream, size_t size){
    char **toRet = (char**)calloc(size, sizeof(char*));
    for(int i = 0; i < size; i++){
        toRet[i] = calloc(MAX_CHARS, sizeof(char));
        fscanf(stream, "%s", toRet[i]);
        toRet[i][MAX_CHARS-1] = '\0';
    }
    return toRet;
}

void FreeAllocatedMemory(char **ptr, size_t len){
    for(int i = 0; i < len; i++)
        free(ptr[i]);

    free(ptr);
}