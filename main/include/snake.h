#ifndef SNAKE
#define SNAKE

#include "board.h"
#include "arraydeque.h"

typedef struct snake_part{
  int x;
  int y;
}snake_part;

typedef struct snake* snake_t;

snake_t make_snake(const int cap);

void snake_add_part(snake_t s,snake_part p);

void draw_buffer(board_t b,snake_part* p);

void draw_snake(snake_t s,board_t b);

void move_snake(snake_t s,int c);

snake_part_queue* get_body(const snake_t s);

#endif
