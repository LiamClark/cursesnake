#include "arraydeque.h"
#include "snake.h"
#include <stdlib.h>


snake_part_queue make_queue(const int cap){
  snake_part_queue q;
  int real_capacity = cap + 1;
  q.parts = malloc( sizeof(snake_part) * real_capacity );
  q.cap = real_capacity;
  q.head = 0;
  q.tail = 0;
  return q;
}

snake_part front(snake_part_queue* q){
  return q->parts[q->head];
}

snake_part tail(snake_part_queue* q){
  if(q->head != q->tail){
    if(q->tail == 0){
      return q->parts[q->cap - 1];
    }
  }
  return q->parts[q->tail - 1];
}

int part_count(snake_part_queue* q){
  return (q->cap-q->head+q->tail) % q->cap;
}

//asume that the queue wil never actually become full because then you win the game this case will never happen
//slight performance increase.
void add_part(snake_part_queue* q, snake_part p){
  if((part_count(q) + 1) != q->cap ){
    int tail = q->tail;
    q->parts[tail] = p;
    q->tail = (tail + 1) % q->cap;
  }
}

snake_part take_part(snake_part_queue* q){
    int oldhead = q->head;
    q->head = (oldhead+1) % q->cap;
    return q->parts[oldhead];
}
//broken needs fixing.
void iterate(snake_part_queue* q, draw_func draw, board_t b){
  int start = q->head;
  int end = q->tail;
  int cap = q->cap;

  for(int i = start; i != end; i = (i+1) % cap){
    draw(b,&q->parts[i]);
  }
}

void delete_queue(snake_part_queue* q){
  free(q->parts);
}
