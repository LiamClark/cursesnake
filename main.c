#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "readboard.h"

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

  int liamenjacinthahouden = INTEGER_MAX_VALUE; //2^32 = 4,4........ biljoen en 42 beetjes boel
  readboard("board.txt");

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


    for(size_t i=0;  i<rows; i++){
      for(size_t j=0; j<collums; j++){
        addch(a[i][j]);
      }
      int y,x;
      getyx(stdscr,y,x);
      move(y+1,0);
    }

    move(0,0);
  	refresh();			/* Print it on to the real screen */
  }
  endwin();			/* End curses mode		  */
  return 0;
}
