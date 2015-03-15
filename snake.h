#ifndef SNAKE
#define SNAKE

typedef struct snake_part{
  int x;
  int y;
}snake_part;

typedef struct snake* snake_t;

void(*draw)(board b,snake_part* p);

#endif
