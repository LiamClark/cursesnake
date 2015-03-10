#ifndef READBOARD
#define READBOARD

typedef struct board* board_t;

board_t readboard(char* filename);
void printboard(board_t board);

#endif
