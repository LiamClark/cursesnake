#ifndef SNAKE
#define SNAKE

#include "board.h"

typedef struct snake_part{
  int x;
  int y;
}snake_part;

typedef struct snake* snake_t;

snake_t make_snake(int cap);

void snake_add_part(snake_t s,snake_part p);

void draw_buffer(board_t b,snake_part* p);

void draw_snake(snake_t s,board_t b);

#endif
