#include "arraydeque.h"
#include "snake.h"



// typedef struct snake_part_queue{
//   snake_part* parts
//   int head=0;
//   int tail=0;
//   int cap;
// }snake_part_queue;


snake_part front(snake_part_queue* q){
  return q->parts[q->head];
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
    int head=q->head;
    q->parts[head] = p;
    q->head = (head+1) % q->cap;
}

snake_part take_part(snake_part_queue* q){
    int oldtail=q->tail;
    q->tail = (oldtail+1) % q->cap;
    return q->parts[oldtail];
}

void iterate(snake_part_queue* q ,void(*draw)(board_t b,snake_part* p),board_t b){
  int start = q->tail;
  int end =q->head;
  int cap =q->cap;

  for(int i =start; i!=end; i=(i+1)%cap){
    draw(b,&q->parts[i]);
  }
}
