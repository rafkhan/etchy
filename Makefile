CC=gcc
CFLAGS=-Wall -lncurses -pedantic -ansi -g

main: etchy.c
	$(CC) $(CFLAGS) etchy.c -o etchy

clean:
	rm etchy -I
