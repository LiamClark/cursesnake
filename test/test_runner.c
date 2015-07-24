#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include "board_test.h"

int main(int argc, char** argv){
  if( CUE_SUCCESS != CU_initialize_registry()){
    return CU_get_error();
  }
  CU_pSuite board = getBoardSuite();
  CU_basic_set_mode(CU_BRM_NORMAL);
  int err = CU_basic_run_tests();

  CU_cleanup_registry();

  return err;
}
