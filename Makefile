CC = gcc
CFLAGS = -std=c99 -Wall -g
LDFLAGS = -lncurses -L/usr/lib/
SOURCES = $(wildcard *.c)
all:
	$(CC) $(CFLAGS) $(SOURCES) -o snake.out $(LDFLAGS)
