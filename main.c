#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "snake.h"


const size_t rows=10;
const size_t collums=20;


int main(int argc, char** argv){
  board_t board = readboard("./board.txt");
  snake_t snake = make_snake(rows*collums);
  snake_part new_part={1,1};
  snake_add_part(snake,new_part);
  new_part.y=2;
  snake_add_part(snake,new_part);
  draw_snake(snake,board);

  int ch;

	initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */
  for(;;){
  	ch = getch();
    if (ch == 'q'){
      break;
    }

    printboard(board);

    move(0,0);
  	refresh();			/* Print it on to the real screen */
  }
  endwin();			/* End curses mode		  */
  return 0;
}
