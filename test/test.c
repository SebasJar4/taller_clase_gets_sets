#include"specifics/data_structs.h"
#include"specifics/gets_sets_student.h"
#include<stdio.h>
#include<stdlib.h>

int main ( void ) {
  Student student;
  set_all_of_student( &student );
  print_student( &student );
  return EXIT_SUCCESS;
}