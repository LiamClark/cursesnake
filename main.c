#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "board.h"

const size_t rows=10;
const size_t collums=20;


int main(int argc, char** argv){
  char** a = malloc(rows*sizeof(char*));
  char*  b = malloc(rows*collums*sizeof(char));

  for(size_t i=0; i<rows;i++){
    a[i] = &b[i*collums];
  }

  for(size_t i=0;  i<rows; i++){
    for(size_t j=0; j<collums; j++){
      a[i][j]='a';
    }
  }
  board_t board = readboard("./board.txt");

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
