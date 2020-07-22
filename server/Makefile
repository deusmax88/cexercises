CC=cc

all: server client

common.o: common.c
	$(CC) -c $^

server: server.c common.o
	$(CC) -o $@ $^

client: client.c
	$(CC) -o $@ $^

clean:
	rm *.o server client