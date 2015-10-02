#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct board{
  char** matrix;
  int width;
  int height;
}board;

static const char SPACE = ' ';

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
  fclose(board_file);
  return board;
}

board_t make_board(char* const* board_format, const int width, const int height) {
  board_t board = malloc(sizeof(struct board));

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

void delete_board(board_t board) {
  delete_contigous_array(board->matrix);
  free(board);
}

void set_tile(board_t b,int y, int x, char c) {
  b->matrix[y][x] = c;
}

char get_tile(board_t b,int y, int x) {
  return b->matrix[y][x];
}


bool int_in_range(int point, int max) {
  return 0 <= point && point < max;
}

bool is_in_range(board_t board, snake_part part) {
  return int_in_range(part.x, board->width) &&
            int_in_range(part.y, board->height);
}

void printboard(board_t board) {
  int height = board->height;
  int width = board->width;
  char** matrix = board->matrix;

  for(size_t i = 0; i < height; i++) {
    for(size_t j = 0; j < width; j++) {
      addch(matrix[i][j]);
    }
    int y,x;
    getyx(stdscr,y,x);
    move(y+1,0);
  }
}

int count_free_tiles(board_t board) {
  size_t size = board->width * board->height;
  char* tiles = *board->matrix;
  int available_tiles = size;
  for (size_t i = 0; i < size; ++i) {
    char tile = tiles[i];
    if (tile != SPACE) {
      available_tiles--;
    }
  }
  return available_tiles;
}

void fill_free_tiles(board_t board, char** tiles) {
  size_t size = board->width * board->height;
  char* btiles = *board->matrix;
  for (size_t i = 0, index = 0; i < size; ++i) {
    char tile = btiles[i];
    if (tile == SPACE) {
      tiles[index] = &btiles[i];
      index++;
    }
  }
}

char** create_free_tile_array(board_t) {
  int no_tiles =  count_free_tiles(board);
  //one dimensional array of char pointers
  //alocate the memory.
  char** tiles = malloc(sizeof(char*)*no_tiles);
  fill_free_tiles(board,tiles);
}

void add_apple(board_t board) {

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
