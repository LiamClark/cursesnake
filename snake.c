#include "snake.h"
#include "stdlib.h"
#include "arraydeque.h"
#include "board.h"

typedef struct snake{
  snake_part_queue body;
}snake;


snake_t make_snake(int cap){
  snake_t s= malloc(sizeof(snake));
  s->body.parts = malloc(sizeof(snake_part)*cap);
  snake_part_queue* q = &(s->body);
  q->cap = cap;
  q->head=0;
  q->tail=0;
  return s;
}

void snake_add_part(snake_t s,snake_part p){
  add_part(&(s->body),p);
}

void draw_snake(snake_t s,board_t b){
  iterate((&s->body),draw_buffer,b);
}
void draw_buffer(board_t b,snake_part* p){
  setchar(b,p->x,p->y,'X');
}
