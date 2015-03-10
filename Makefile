CC = clang
CFLAGS = -std=c99 -lncurses -Wall -g
SOURCES = $(wildcard *.c)
all:
	$(CC) $(CFLAGS) $(SOURCES) -o snake.out
