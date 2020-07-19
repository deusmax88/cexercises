#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void* myturn(void * arg) {
    int *j = (int *) malloc(sizeof(int));
    *j = 5;
    for(int i = 0; i < 8; i++) {
        sleep(1);
        printf("My Turn! %d %d\n", i, *j);
        (*j)++;
    }
    
    return j;
}

void yourturn() {
    for(int i = 0; i < 3; i++) {
        sleep(2);
        printf("Our Turn! %d\n", i);
    }
}

int main() {
    pthread_t newthread;
    int* result;

    pthread_create(&newthread, NULL, myturn, NULL);
    yourturn();

    pthread_join(newthread,(void *) &result);
    printf("thread's done: result=%d", *result);
}