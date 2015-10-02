#ifndef READBOARD
#define READBOARD

#include "stdbool.h"
#include "snakepart.h"

typedef struct board* board_t;


board_t read_board(const char* filename);
board_t make_board(char* const* board, const int width, const int height);

void delete_board(board_t board);

void set_tile(board_t b, const int y, const int x, char c);
char get_tile(board_t b, const int y, const int x);

int count_free_tiles(board_t board);
char** create_free_tile_array(board_t,int*);

bool is_in_range(board_t board, snake_part part);

void printboard(board_t board);
void printfboard(board_t board);

#endif
