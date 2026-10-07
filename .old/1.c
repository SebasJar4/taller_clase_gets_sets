#include<stdio.h>
#include<stdlib.h>
#include"lib/specifics/gets_sets_student.h"
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define NUMBER_ESTUDENTS 3

int get_option();
bool are_the_same( char * str1 , size_t size1 , char * str2 , size_t size2 );

int main ( void ) {
  Student list_estudents[ NUMBER_ESTUDENTS ];
  for ( int i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) {
    printf("@@@Estudiante %d de %d" , i + 1 , NUMBER_ESTUDENTS );
    press_enter_to_continue();
    set_all_of_student( list_estudents + i );
  }

  // for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) print_student( list_estudents + i );

  int option;
  char *data;

  while ( true ) {
    if ( get_yes_or_not("salir?") ) break; 
    option = get_option();
    

    if ( option == 1 ) data = get_code();
    if ( option == 2 ) data = get_name();

    for ( int i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) {
      if ( option == 1 && are_the_same( data , strlen(data) , list_estudents[i].code , NAME_SIZE ) ) print_student( list_estudents + i );
      if ( option == 2 && are_the_same( data , strlen(data) , list_estudents[i].name , NAME_SIZE )) print_student( list_estudents + i );
    }
    free( data );
  }

  printf("\n");
  
  return 0;
}

int get_option() { 
  int input;
  while ( true ) {
    printf("Seleccione una opcion: \n 1. Ver estudiante por codigo \n 2. Ver a estudiante por nombre\n" );
    input = get_input_int("la opcion");
    if ( input >= 1 && input <= 2 ) break;
    print_input_exception("La entrada es invalida....");
  }
  return input;
}

bool are_the_same( char * str1 , size_t size1 , char * str2 , size_t size2 ) {
  assert( str1 != NULL && strlen(str1) > 0);
  assert( str2 != NULL && strlen(str2) > 0);
  
  size_t i, j;
  i = j = 0;

  bool a , b;
  a = b = false;

  while ( !a || !b ) {
    if ( str1[ i ] != str2[ i ] ) return false;
    if ( str1[ i ] != '\0' && i < size1 ) i ++; else a = true;
    if ( str2[ j ] != '\0' && j < size2 ) j ++; else b = true;
  }

  return true;
}