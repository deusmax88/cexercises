
BINS = selectserver testing_client

all: selectserver testing_client

selectserver: selectserver.c
	$(CC) -o $@ $^

testing_client: testing_client.c
	$(CC) -o $@ $^

clean:
	rm selectserver testing_client