CC=gcc
CFLAGS=-I.

%.o: %.c
	$(CC) -c -o $@ $<

tcp_server: tcp_server.o
	$(CC) -o $@ $^

tcp_client: tcp_client.o
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o *~ core