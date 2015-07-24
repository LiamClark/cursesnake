#include <CUnit/CUnit.h>
#include "board_test.h"
#include "board.h"


const char* test_board[] =
{
  "###",
  "# #",
  "# #",
  "###"
};

const int width = 3;
const int height = 4;

board_t board;

int setup(void){
  board = make_board(test_board,width,height);
  return 0;
}

int after(void){
  return 0;
}

void make_board_test(void){
  for (int i = 0; i < width; i++) {
    for(int j = 0; j < height; j++ ) {
        CU_ASSERT_EQUAL(test_board[i][j], get_tile(board,i,j));
    }
  }
}


CU_pSuite getBoardSuite(void){
  CU_pSuite suite = CU_add_suite("board-suite",setup,after);
  CU_add_test(suite,"make_board_test",make_board_test);

  return suite;
}
