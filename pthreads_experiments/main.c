#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void * threadFunction (void * arg) {
    int * threadArg = malloc(sizeof(*threadArg));
    threadArg = (int *)arg;
    printf("Got arg %d\n", *threadArg);
    
    (*threadArg)++;
    
    return (void *) threadArg;
}

int main(int argc, char** argv) {

    int num_of_threads = atoi(argv[1]);

    pthread_t* tids = (pthread_t*) malloc(sizeof(pthread_t) * num_of_threads);
    int * arg = (int *)malloc(sizeof(*arg));
    *arg = 1;

    for (int i = 0; i < num_of_threads; i++) {
        pthread_create(&tids[i], NULL, threadFunction, arg);
    }

    int total = 0;
    int* res;
    for (int i = 0; i < num_of_threads; i++) {
        pthread_join(tids[i],(void **) &res);
        printf("%d", *(res));
        total += *(res);
    }

    printf ("Got total %d\n", total);
}