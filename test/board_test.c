#include <CUnit/CUnit.h>
#include "board_test.h"
#include "board.h"

int setup(void){
  return 0;
}

int after(void){
  return 0;
}

void simple_test(void){
  board_t board = readboard("test/res/board.txt");
  CU_ASSERT(1);
}


CU_pSuite getBoardSuite(void){
  CU_pSuite suite = CU_add_suite("board-suite",setup,after);
  CU_add_test(suite,"simple_test",simple_test);

  return suite;
}
