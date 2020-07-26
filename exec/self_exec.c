#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int favNum = 42;

int main (int argc, char** argv) {
    printf("execDemo: My pid is %d\n", getpid());
    printf("fav num is %d\n", favNum);

    char* args[] = {"./a.out", "Hello", "World", NULL};
    execvp("./a.out", args);

    printf("execDeom original");
    return 0;
}