#include "snake.h"
#include "stdlib.h"
#include "arraydeque.h"
#include "board.h"
#include <ncurses.h>

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

//didn't care about the x,y stuff
void draw_buffer(board_t b,snake_part* p){
  set_tile(b,p->y,p->x,'X');
}

void move_snake(snake_t s,int c){
  snake_part_queue* q = &(s->body);
  snake_part head = front(q);
  switch (c){
      case KEY_UP :
        head.y=head.y-1;
        break;
      case KEY_DOWN :
        head.y=head.y+1;
        break;
      case  KEY_LEFT :
        head.x=head.x-1;
        break;
      case KEY_RIGHT:
        head.x=head.x+1;
        break;
  }
  add_part(q,head);
}
