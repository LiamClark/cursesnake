#ifndef READBOARD
#define READBOARD

typedef struct board* board_t;

board_t read_board(const char* filename);
board_t make_board(char* const* board, const int width, const int height);

void delete_board(board_t board);

void set_tile(board_t b, int y, int x, char c);
char get_tile(board_t b,int y, int x);

void printboard(board_t board);
void printfboard(board_t board);

#endif
