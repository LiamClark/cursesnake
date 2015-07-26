CC = gcc
CFLAGS = -std=c11 -Wall -g -I main/include -I test/include
LDFLAGS = -lncurses

OUT = snake
TOUT= tsnake

ODIR = obj
SDIR = main
TDIR = test

_MOBJS = arraydeque.o board.o snake.o
_TOBJS = test_runner.o board_test.o snake_test.o array_deque_test.o
EXEC = $(ODIR)/main.o
MAINOBJS =	$(patsubst %,$(ODIR)/%,$(_MOBJS))
TESTOBJS =  $(patsubst %,$(ODIR)/%,$(_TOBJS))

$(ODIR)/%.o: $(TDIR)/%.c
	$(CC) $(CFLAGS) -c $(INC)	-o $@ $<

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $(INC)	-o $@ $<

tests: $(MAINOBJS) $(TESTOBJS)
	$(CC) $(TESTOBJS) $(MAINOBJS) $(LDFLAGS) -lcunit -o $(TOUT)

all: $(MAINOBJS) $(EXEC)
	$(CC)  $(MAINOBJS) $(EXEC) -o $(OUT) $(LDFLAGS)

.PHONY: clean

clean:
	rm $(ODIR)/*.o $(OUT) $(TOUT)
