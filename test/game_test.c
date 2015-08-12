#include "tests.h"
#include "game.h"

int setup_game(void) {
  return 0;
}

int teardown_game(void) {
  return 0;
}


CU_pSuite get_game_suite(void) {
  CU_pSuite suite = CU_add_suite("game-suite",setup_game, teardown_game);
  return suite;
}
