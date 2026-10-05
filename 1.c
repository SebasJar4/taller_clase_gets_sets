#include<stdio.h>
#include"lib/generals/input_functions.h"

typedef struct {
  char code[10];
  char name[12];
  char last_name[12];
  char carrer[15];
  int sem;
  char faculty[20]; 
} Student;

#define NUMBER_ESTUDENTS 3

void get_code ( char * code , size_t size );

int main ( void ) {
  Student list_estudents[ NUMBER_ESTUDENTS ];
  for ( int i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) {

  } 
  return 0;
}