#ifndef ARRAYDEQUE
#define ARRAYDEQUE

#include "snake.h"

typedef struct snake_part_queue{
  snake_part* parts;
  int head;
  int tail;
  int cap;
}snake_part_queue;



#endif
