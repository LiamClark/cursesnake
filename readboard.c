#include <stdio.h>
#include "readboard.h"


char** readboard(char* filename){
  FILE* board = fopen("r",filename);
  int widht, heigth;
  fscanf(board,"%d\n%d\n",&heigth,&widht);
  printf("%d\n%d\n",widht,heigth);
  return NULL;
}
