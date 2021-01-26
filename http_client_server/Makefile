CC=gcc
CFLAGS=-I.

OBJ = http_server.o

%.o: %.c
	$(CC) -c -o $@ $<

http_server: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o *~ core