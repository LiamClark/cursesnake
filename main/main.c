#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "snake.h"

const size_t rows = 10;
const size_t collums = 20;


int main(int argc, char** argv){
  board_t board = read_board("main/res/board.txt");
  snake_t snake = make_snake(rows*collums);
  int ch;

	initscr();			// Start curses mode
	raw();				// Line buffering disabled
	keypad(stdscr, TRUE);		// We get F1, F2 etc..
	noecho();			// Don't echo() while we do getch
  for(;;){
  	ch = getch();
    if (ch == 'q'){
      break;
    }
    move_snake(snake,ch);
    draw_snake(snake,board);
    printboard(board);

    move(0,0);
  	refresh();			// Print it on to the real screen
  }
  endwin();			// End curses mode
  return 0;
}
