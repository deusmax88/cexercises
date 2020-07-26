#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 20000000
long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void * arg) {
    int offset = *(int*)arg;
    for (int i = 0; i < NUM_LOOPS; i++) {
        pthread_mutex_lock(&mutex);
        sum += offset;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {

    pthread_t tid;
    int offset = 1;
    pthread_create(&tid, NULL, thread_function, &offset);

    pthread_t tid2;
    int offset2 = -1;
    pthread_create(&tid2, NULL, thread_function, &offset2);

    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);

    printf("Sum = %lld\n", sum);
    return 0;
}