#include "arraydeque.h"
#include "snake.h"
#include <stdlib.h>


snake_part_queue make_queue(const int cap){
  snake_part_queue q;
  q.parts = malloc( sizeof(snake_part) * cap );
  q.cap = cap;
  q.head = 0;
  q.tail = 0;
  return q;
}

snake_part front(snake_part_queue* q){
  return q->parts[ q->head - 1];
}

snake_part tail(snake_part_queue* q){
  return q->parts[q->tail];
}

int part_count(snake_part_queue* q){
  return (q->cap-q->head+q->tail) % q->cap;
}

//asume that the queue wil never actually become full because then you win the game this case will never happen
//slight performance increase.
void add_part(snake_part_queue* q, snake_part p){
    int head = q->head;
    q->parts[head] = p;
    q->head = (head+1) % q->cap;
}

snake_part take_part(snake_part_queue* q){
    int oldtail=q->tail;
    q->tail = (oldtail+1) % q->cap;
    return q->parts[oldtail];
}

void iterate(snake_part_queue* q ,draw_func draw,board_t b){
  int start = q->tail;
  int end = q->head;
  int cap = q->cap;

  for(int i = start; i != end; i = (i+1) % cap){
    draw(b,&q->parts[i]);
  }
}

void delete_queue(snake_part_queue* q){
  free(q->parts);
}
