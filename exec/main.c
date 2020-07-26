#include <stdio.h>
#include <unistd.h>

int favNum = 84;

int main(int argc, char** argv) {
    printf("exec.c fav num is %d\n", favNum);
    printf("    My PID %d.\n", getpid());

    printf("    My arguments: ");
    for (int i = 0; i < argc; i++) {
        printf("%s", argv[i]);
    }

    printf("\n");

    return 0;
}