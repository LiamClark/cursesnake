#include "snake.h"
#include "stdlib.h"
#include "arraydeque.h"




typedef struct snake{
  snake_part_queue body;
}snake;

snake_t make_snake(int cap){
  snake_t s= malloc(sizeof(snake));
  s->body.parts = malloc(sizeof(snake_part)*cap);
  s->body.cap = cap;
  return s;
}

void(*draw)(board b,snake_part* p){
  b->matrix[p->x][p->y] = 'X';
}
