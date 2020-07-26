#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int i = 0;
void doSomeWork(char * name) {
    int NUM_TIMES = 5;
    for (; i < NUM_TIMES; i++) {
        sleep(rand() % 4);
        printf("Done pass %d for %s\n", i, name);
    }
}

int main (int argc, char** argv) {
    printf("I am: %d\n", (int) getpid());

    pid_t pid = fork();
    srand((int) pid);
    printf("fork returned %d\n", (int) pid);
    if (pid < 0) {
        perror("Fork failed");
    }
    if (pid == 0) {
        printf("I am the child with pid %d\n", (int) getpid());
        doSomeWork("Child");
        printf("Child exiting...\n");
        exit(42);
    }

    printf("I am the parent, waiting for child to end.\n");
    doSomeWork("Parent");
    int status = 0;
    pid_t childpid = wait(&status);
    printf("Parent knows child %d finished %d.\n", (int)childpid, status);
    int childReturnValue = WEXITSTATUS(status);
    printf("   Return value was %d\n", childReturnValue);

    return 0;
}