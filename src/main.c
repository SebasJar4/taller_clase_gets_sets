#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#include"specifics/gets_sets_student.h"
#include"specifics/data_structs.h"

#define NUMBER_ESTUDENTS 3

int get_option();
bool are_the_same( char * str1 , size_t size1 , char * str2 , size_t size2 );
char * get_unique_code ( const Student *list_students , size_t size );

int main ( void ) {
  Student list_students[ NUMBER_ESTUDENTS ]; // heap stack
  for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) {
    printf( "\n@@@ Vamos a ingresar los datos del estudiante %lu de %u" , (i + 1) , NUMBER_ESTUDENTS );
    press_enter_to_continue();
  
    list_students[i].code = get_unique_code( list_students , i );
    set_all_of_student_without_code( list_students + i );
    printf("\n");
  }

  for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) print_student( list_students + i );

  int option;
  char *data;
  
  while ( true ) {

    if ( get_yes_or_not("\n Salir?") ) break; 
    
    option = get_option();
    
    if ( option == 1 ) {
      data = get_code();
      for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) if ( are_the_same( data , strlen(data) , list_students[i].code , NAME_SIZE ) ) print_student( list_students + i );
      continue;
    } else if ( option == 2 ) { 
      data = get_name();
      for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) if ( are_the_same( data , strlen(data) , list_students[i].name , NAME_SIZE ) ) print_student( list_students + i );
    } else if ( option == 3 ) { 
      data = get_last_name();
      for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) if ( are_the_same( data , strlen(data) , list_students[i].last_name , NAME_SIZE ) ) print_student( list_students + i ); 
    } else if ( option == 4 ) { 
      data = get_carrer();
      for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) if ( are_the_same( data , strlen(data) , list_students[i].carrer , NAME_SIZE ) ) print_student( list_students + i ); 
    } else if ( option == 5 ) { 
      data = get_faculty();
      for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ )
        if ( are_the_same( data , strlen(data) , list_students[i].faculty , NAME_SIZE ) ) print_student( list_students + i ); 
    } else if ( option == 6 ) {
      int sem = get_semester();
      for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ )
        if ( list_students[ i ].sem == sem ) print_student( list_students + i );
    } else if ( option == 7 ) {
      for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) print_student( list_students + i );
      continue;
    }

    free( data );
  }

  printf("\n");
  
  for ( size_t i = 0 ; i < NUMBER_ESTUDENTS ; i ++ ) free_student( list_students + i );

  return 0;
}

int get_option() { 
  int input;
  while ( true ) {
    printf("Seleccione una opcion: \n 1. Ver estudiante por codigo \n 2. Ver a estudiante por nombre\n 3. Ver estudiante por Apellido\n 4. Ver estudiante por Carrera\n 5. Ver estudiante por Facultad\n 6. Ver estudiante por semestre\n 7. Ver todos los estudiante\n" );

    input = get_input_int("la opcion");

    if ( input >= 1 && input <= 7 ) break;
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

char * get_unique_code ( const Student *list_students , size_t size ) {

  assert( list_students != NULL );

  char * tmp_code;
  bool already_exist = false;
  
  while ( true ) {
    already_exist = false;
    tmp_code = get_code();
    for ( size_t i = 0 ; i < size ; i ++ ) {
      if( are_the_same( list_students[ i ].code , CODE_SIZE , tmp_code , CODE_SIZE ) ) { 
        already_exist = true;
        free( tmp_code );
        break;
      }
    }
    if ( !already_exist ) break;
    print_input_exception("El codigo de estudiante ingresado ya existe, por favor digite uno nuevo...");
  }
  
  return tmp_code;
}