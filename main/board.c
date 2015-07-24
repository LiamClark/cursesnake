#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

typedef struct board{
  char** matrix;
  int width;
  int height;
}board;


board_t read_board(const char* filename){
  board_t board = malloc(sizeof(board));
  FILE* board_file = fopen(filename,"r");
  //get  the board sizes
  fscanf(board_file,"%d\n%d\n",&board->width,&board->height);
  int height = board->height;
  int width = board->width;

  char** matrix = malloc(height*sizeof(char*));
  char*  contigousarray = malloc(height*width*sizeof(char));
  //set up our matrix as a 1d array but with subscript operators
  for(size_t i=0; i < height;i++){
    matrix[i] = &contigousarray[i*width];
  }
  //fill the array from
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      matrix[i][j] = fgetc(board_file);
    }
    // skip the new line
    fgetc(board_file);
  }
  //copy in the pointer to the matrix
  board->matrix = matrix;
  return board;
}

board_t make_board(const char** board_format, const int width, const int height){
  board_t board = malloc(sizeof(board));

  char** matrix = malloc(height * sizeof(char*));
  char*  contigousarray = malloc(height * width * sizeof(char));
  // first index is the y coordinate
  for(size_t i = 0; i < height; i++){
    matrix[i] = &contigousarray[i * width];
  }

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++) {
      matrix[i][j] = board_format[i][j];
    }
  }

  board->matrix = matrix;
  return board;
}

void set_tile(board_t b,int y, int x, char c){
  b->matrix[y][x] = c;
}

char get_tile(board_t b,int y, int x){
  return b->matrix[y][x];
}


void printboard(board_t board){
  int height = board->height;
  int width = board->width;
  char** matrix = board->matrix;

  for(size_t i=0; i < height; i++) {
    for(size_t j = 0; j < width; j++) {
      addch(matrix[i][j]);
    }
    int y,x;
    getyx(stdscr,y,x);
    move(y+1,0);
  }
}
