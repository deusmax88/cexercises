CC=cc
CFLAGS=-Wall -g

BINS=libplus1.so libplus2.so test

all: $(BINS)

%.so: 	%.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^

test: test.c
	$(CC) $(CFLAGS) -o $@ $^ -ldl

clean:
	rm $(BINS)
