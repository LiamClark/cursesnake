#include "snake_test.h"

int setup(void){
  return 0;
}

int after(void){
  return;
}

void make_snake_test(void){
  snake_t make_snake()
}



CU_pSuite get_snake_suite(void);
  CU_pSuite suite = CU_add_suite("snake-suite",setup,after);

  CU_add_test(suite,"make_board_test",make_board_test);


  return suite;
}
