#include <CUnit/CUnit.h>
#include "tests.h"
#include "board.h"


static char* const test_board[] =
{
  "123",
  "456"
};

static const int width = 3;
static const int height = 2;

const char expected[] = "123456";

board_t board;

int setup(void) {
  board = make_board(test_board, width, height);
  return 0;
}

int after(void) {
  delete_board(board);
  board = NULL;
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

void read_board_test(void) {
  int res = 0;
  const char expected[] = "#### #";
  board_t fboard = read_board("test/res/board.txt");

  for(int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
        CU_ASSERT_EQUAL( expected[res] , get_tile(fboard,y,x));
        res++;
    }
  }
  delete_board(fboard);
}

void set_tile_test(void) {
  const int y = 1, x = 2;
  const char expected = 's';
  set_tile(board,y,x,expected);
  char result = get_tile(board,y,x);
  CU_ASSERT_EQUAL(expected,result);
}

void is_in_range_test(void) {
  snake_part in_range = {1,1};
  snake_part out_of_range = {3,3};
  CU_ASSERT_TRUE(is_in_range(board,in_range));
  CU_ASSERT_FALSE(is_in_range(board,out_of_range));
}


CU_pSuite get_board_suite(void){
  CU_pSuite suite = CU_add_suite("board-suite",setup,after);

  CU_add_test(suite,"make_board_test",make_board_test);
  CU_add_test(suite,"set_tile_test",set_tile_test);
  CU_add_test(suite,"read_board_test",read_board_test);
  CU_add_test(suite,"is_in_range_test",is_in_range_test);

  return suite;
}
