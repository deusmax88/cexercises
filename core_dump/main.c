#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

int main () {
    int rnum = 0;
    int* goodptr = malloc(sizeof(int));
    int* badptr = NULL;

    srand(time(NULL));
    while(true) {
        rnum = rand() % 255;
        if (rnum == 13) {
            *badptr = rnum;
        }
        else {
            *goodptr = rnum;
        }
        printf("random: %d\n", rnum);
        usleep(100);
    }
}