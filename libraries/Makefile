CC=cc

CFLAGS=-Wall -g

BINS=libmytest libmycode.so libmycode_static.a runtime_libmytest static_libmytest 

all: $(BINS)

libmycode.o: libmycode.c libmycode.h
	$(CC) $(CFLAGS) -c libmycode.c

libmytest: libmytest.c libmycode.o
	$(CC) $(CFLAGS) -o $@ $^

libmycode.so: libmytest.c libmycode.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ libmycode.c -lc

libmycode_static.a: libmycode.o
	ar rcs $@ libmycode.o

runtime_libmytest: libmytest.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lmycode

static_libmytest: libmytest.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lmycode_static

clean:
	rm *.o $(BINS)