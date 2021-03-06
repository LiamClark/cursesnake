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

input_error is_valid_key(int key) {
  input_error error = INPUT_INVALID_KEY;
  if ( (KEY_DOWN <= key && key <= KEY_RIGHT) || key == 'q' ) {
    error = INPUT_OK;
  }
  return error;
}

direction find_direction(int key) {
  return key - KEY_DOWN;
}

snake_part  snake_get_next_move(snake_t s, int c) {
  snake_part_queue* q = &(s->body);
  snake_part head = tail(q);

  switch (c) {
      case UP:
        head.y = head.y - 1;
        break;
      case DOWN:
        head.y = head.y + 1;
        break;
      case LEFT:
        head.x = head.x - 1;
        break;
      case RIGHT:
        head.x = head.x + 1;
        break;
  }
  return head;
}

snake_part apply_move(snake_t s, snake_part part, bool take) {
  snake_part ret = {-1,-1};
  add_part(&s->body,part);
  if(take){
   ret = take_part(&s->body);
  }
  return ret;
}

snake_part_queue* get_body(const snake_t s) {
  return &s->body;
}

void delete_snake(snake_t s) {
  delete_queue(&s->body);
  free(s);
}
