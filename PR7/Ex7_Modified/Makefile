CC = gcc
CFLAGS = -Wall -Wextra

all: server child

server: server.c
	$(CC) $(CFLAGS) -o server server.c

child: child.c
	$(CC) $(CFLAGS) -o child child.c

clean:
	rm -f server child