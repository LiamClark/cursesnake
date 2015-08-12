#include "tests.h"
#include "game.h"
#include <ncurses.h>

static char* const test_board[] =
{
  "#####",
  "#   #",
  "#   #",
  "#   #",
  "#####"
};

static const int width = 5;
static const int height = 5;

board_t board;
snake_t snake;
game_t game;

int setup_game(void) {
  board = make_board(test_board, width, height);
  snake = make_snake(width * height);
  snake_part start = {1,1};
  game = make_game(board, snake, start);
  return 0;
}

int teardown_game(void) {
  delete_board(board);
  delete_snake(snake);
  return 0;
}

void game_loop_test(void) {
  game_loop(game,KEY_DOWN);
}


CU_pSuite get_game_suite(void) {
  CU_pSuite suite = CU_add_suite("game-suite",setup_game, teardown_game);

  CU_add_test(suite,"game_loop_test",game_loop_test);

  return suite;
}
