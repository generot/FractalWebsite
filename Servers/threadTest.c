#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *th(void *args){
    while(1){
        printf("%s\n",(char*)args);
    }
    return NULL;
}
int main(){
    pthread_t thread;

    char *arg = "Thread #2";
    pthread_create(&thread,NULL,&th,arg);
    
    while(1){
        printf("Thread #1\n");
    }
}