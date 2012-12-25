CC=gcc
CFLAGS=-Wall -lncurses

main: etchy.c
	$(CC) $(CFLAGS) etchy.c -o etchy

clean:
	rm etchy -I
