#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "pthread.h"
#include "game.h"

const size_t rows = 10;
const size_t collums = 20;


int main(int argc, char** argv) {

  board_t board = read_board("main/res/board.txt");
  snake_t snake = make_snake(rows * collums);
  snake_part start = {3,4};
  game_t game = make_game(board, snake, start);

	initscr();			// Start curses mode
	raw();				// Line buffering disabled
	keypad(stdscr, TRUE);		// We get F1, F2 etc..
	noecho();			// Don't echo() while we do getch
  nodelay(stdscr,TRUE); //non blocking input mode.

  for(;;) {
    game_error error = game_loop(&game);

    if (error != GAME_OK){
      break;
    }

    printboard(board);

    move(0,0);
  	refresh();			// Print it on to the real screen
  }
  endwin();			// End curses mode
  return 0;
}
