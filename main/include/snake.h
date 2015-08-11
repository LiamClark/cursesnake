#ifndef SNAKE
#define SNAKE

#include "arraydeque.h"
#include "board.h"

typedef struct snake* snake_t;

snake_t make_snake(const int cap);

void draw_buffer(board_t b,snake_part* p);

void draw_snake(snake_t s,board_t b);

void move_snake(snake_t s,int c);

snake_part_queue * get_body(const snake_t s);


#endif
