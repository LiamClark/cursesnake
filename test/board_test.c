#include <CUnit/CUnit.h>
#include "board_test.h"
#include "board.h"


const char* test_board[] =
{
  "123",
  "456"
};

const int width = 3;
const int height = 2;

const char expected[] = "123456";

board_t board;

int setup(void) {
  board = make_board(test_board,width,height);
  return 0;
}

int after(void) {
  return 0;
}

void make_board_test(void) {
  for(int y = 0, res = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
        CU_ASSERT_EQUAL( expected[res] , get_tile(board,y,x));
        res++;
    }
  }
}

CU_pSuite getBoardSuite(void){
  CU_pSuite suite = CU_add_suite("board-suite",setup,after);
  CU_add_test(suite,"make_board_test",make_board_test);

  return suite;
}
