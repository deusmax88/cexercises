#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main (int argc, char** argv) {
    if (argc < 3) {
        printf("usage: %s <library> <number> \n", argv[0]);
        exit(1);
    }

    char *librarypath = argv[1];
    int thenumber = atoi(argv[2]);

    void *libhandle = dlopen(librarypath, RTLD_LAZY);

    if (libhandle == NULL) {
        perror("dlopen");
    }

    int (*opfunc) (int);
    opfunc = dlsym(libhandle, "do_operation");
    if (opfunc == NULL) {
        perror("dlsym error");
    }

    printf("%d --> %d\n", thenumber, opfunc(thenumber));

    dlclose(libhandle);
}