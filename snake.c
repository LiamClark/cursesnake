#include "snake.h"


typedef struct snake_part_queue{
  snake_part* parts
  int head=0;
  int tail=0;
  int cap;
}snake_part_queue;


void add_part(snake_part_queue* q, snake_part p){
    int head= q->head;
    q->parts[head] = p;
    head++;

}






typedef struct snake{
  snake_part_queue body;
}snake;

snake_t make_snake(int cap){
  snake_t s= malloc(sizeof(snake));
  s->body.parts = malloc(sizeof(snake_part)*cap);
  s->body.cap = cap;
  return s;
}
