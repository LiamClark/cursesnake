#ifndef ARRAYDEQUE
#define ARRAYDEQUE

#include "snake.h"

typedef struct snake_part_queue{
  snake_part* parts;
  int head;
  int tail;
  int cap;
}snake_part_queue;

snake_part_queue make_queue(const int capacity);

void add_part(snake_part_queue* q, snake_part p);

void iterate(snake_part_queue* q ,void(*draw)(board_t b,snake_part* p),board_t b);

snake_part front(snake_part_queue* q);

snake_part tail(snake_part_queue* q);

snake_part take_part(snake_part_queue* q);

#endif
