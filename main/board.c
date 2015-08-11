#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

typedef struct board{
  char** matrix;
  int width;
  int height;
}board;

char** make_contiguous_array(const int width, const int height) {
  char** matrix = malloc(height * sizeof(char*));
  char*  contigousarray = malloc(height * width * sizeof(char));
  // first index is the y coordinate
  for(size_t i = 0; i < height; i++){
    matrix[i] = &contigousarray[i * width];
  }

  return matrix;
}

void delete_contigous_array(char** ca) {
  free(ca[0]);
  free(ca);
}

board_t read_board(const char* filename) {
  int height,width;
  FILE* board_file = fopen(filename,"r");
  //get  the board sizes
  fscanf(board_file,"%d\n%d\n",&width,&height);

  char** board_format = make_contiguous_array(width,height);
  //fill the array from
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      board_format[i][j] = fgetc(board_file);
    }
    // skip the new line
    fgetc(board_file);
  }
  board_t board = make_board(board_format,width,height);

  delete_contigous_array(board_format);

  return board;
}

board_t make_board(char* const* board_format, const int width, const int height) {
  board_t board = malloc(sizeof(board));

  char** matrix = make_contiguous_array(width,height);

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++) {
      matrix[i][j] = board_format[i][j];
    }
  }

  board->matrix = matrix;
  board->width = width;
  board->height = height;
  return board;
}

void delete_board(board_t board){
  delete_contigous_array(board->matrix);
  free(board);
}

void set_tile(board_t b,int y, int x, char c){
  b->matrix[y][x] = c;
}

char get_tile(board_t b,int y, int x){
  return b->matrix[y][x];
}


void printboard(board_t board) {
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

void printfboard(board_t board){
  int height = board->height;
  int width = board->width;
  char** matrix = board->matrix;

  for(size_t i=0; i < height; i++) {
    for(size_t j = 0; j < width; j++) {
      printf("%c",(matrix[i][j]));
    }
    printf("\n");
  }
}
