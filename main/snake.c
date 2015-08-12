#include "snake.h"
#include "stdlib.h"
#include "arraydeque.h"
#include "board.h"
#include <ncurses.h>

typedef struct snake{
  snake_part_queue body;
}snake;


snake_t make_snake(const int cap) {
  snake_t s = malloc( sizeof(struct snake));
  s->body = make_queue(cap);
  return s;
}

void draw_snake(snake_t s,board_t b) {
  iterate((&s->body),draw_buffer,b);
}

void draw_buffer(board_t b,snake_part* p) {
  set_tile(b,p->y,p->x,'X');
}

snake_part  snake_get_next_move(snake_t s, int c) {
  snake_part_queue* q = &(s->body);
  snake_part head = tail(q);
  switch (c) {
      case KEY_UP:
        head.y = head.y - 1;
        break;
      case KEY_DOWN:
        head.y = head.y + 1;
        break;
      case  KEY_LEFT:
        head.x = head.x - 1;
        break;
      case KEY_RIGHT:
        head.x = head.x + 1;
        break;
  }
  return head;
}

void apply_move(snake_t s , snake_part part) {
  add_part(&s->body,part);
}

snake_part_queue* get_body(const snake_t s) {
  return &s->body;
}

void delete_snake(snake_t s) {
  delete_queue(&s->body);
  free(s);
}
