#ifndef ARRAYDEQUE
#define ARRAYDEQUE

#include "board.h"


typedef struct snake_part{
  int x;
  int y;
}snake_part;

typedef struct snake_part_queue{
  snake_part* parts;
  int head;
  int tail;
  int cap;
}snake_part_queue;

typedef void (*draw_func)(board_t,snake_part*);

snake_part_queue make_queue(const int capacity);

void add_part(snake_part_queue* q, snake_part p);

int part_count(snake_part_queue* q);

void iterate(snake_part_queue* q ,draw_func func ,board_t b);

snake_part front(snake_part_queue* q);

snake_part tail(snake_part_queue* q);

snake_part take_part(snake_part_queue* q);

void delete_queue(snake_part_queue* q);

#endif
