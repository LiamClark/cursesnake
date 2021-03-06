#ifndef SNAKE
#define SNAKE

#include "arraydeque.h"
#include "board.h"

typedef struct snake* snake_t;

typedef enum input_error {INPUT_OK, INPUT_INVALID_KEY} input_error;
typedef enum direction {DOWN,UP,LEFT,RIGHT} direction;

snake_t make_snake(const int cap);

void draw_buffer(board_t b,snake_part* p);

void draw_snake(snake_t s, board_t b);

direction find_direction(int character);
input_error is_valid_key(int key);

snake_part snake_get_next_move(snake_t s, int c);

//returns the removed part.
snake_part apply_move(snake_t s, snake_part part, bool take);

snake_part_queue * get_body(const snake_t s);

void delete_snake(snake_t s);

#endif
