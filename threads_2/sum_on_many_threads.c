#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * sum_runner(void * arg) {
    long long* limit_ptr = (long long *) arg;
    long long limit = *limit_ptr;
    long long * sum = malloc(sizeof(*sum));
    
    for (long long i = 0; i <= limit; i++) {
        *sum += i;
    }

    pthread_exit(sum);
}

int main (int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <num 1> <num 2> ... <num-n>\n", argv[0]);
        exit(-1);
    }
    int num_args = argc - 1;


    pthread_t tids[num_args];

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    for(int i = 0; i < num_args; i++) {
        long long limit = atoll(argv[i + 1]);
        pthread_create(&tids[i], &attr, sum_runner, &limit);
    }

    long long sum = 0;
    long long * thread_sum;
    for(int i = 0; i < num_args; i++) {
        pthread_join(tids[i], (void **) &thread_sum);
        long long current_sum = *thread_sum;
        sum += current_sum;
    }

    printf("Sum is %lld\n", sum);
}