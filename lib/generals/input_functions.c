#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>


#include "input_functions.h"

// void print_input_exception( char * error ) {
//   assert(error != NULL && strlen(error) > 0);
//   printf("\n!!Error: %s" , error );
//   limpieza_stdin();
//   press_enter_to_continue();
// }

void print_input_exception(const char *format, ...) {
    assert(format != NULL && strlen(format) > 0);

    va_list args;
    va_start(args, format);

    printf("\n!!Error: ");
    vprintf(format, args);

    va_end(args);
    press_enter_to_continue();
}



void limpieza_stdin( void ) {
  int c;
  int count = 0;
  while( ( c = getchar() ) != '\n' && c != EOF && count++ <= 1000 );
}

void press_enter_to_continue( void ) {
  printf("\n>> Presiona enter para continuar <<");
  while( getchar() != '\n' ); 
  printf("\n");
} 

int get_input_int ( char * complete_str_message ) {
  
  assert( complete_str_message != NULL || strlen( complete_str_message ) > 0 ); // Evalue the string input

  int input;
  while ( true ) {
    // input
    printf( "@Ingrese %s > " , complete_str_message );
    int out_scan = scanf( "%d" , &input );
    limpieza_stdin();
    if ( out_scan == 1 ) { break; } // entrada correcta
    // Mensaje de error
    print_input_exception("!!Error, el valor de entrada es invalido");
  }

  return input;
}

double get_input_double ( char * complete_str_message ) {

  assert( complete_str_message != NULL || strlen( complete_str_message ) > 0);
  double input;
  while ( 1 ) {
    // input
    printf( "@Ingrese %s > " , complete_str_message );
    int out_scan = scanf( "%lf" , &input );
    limpieza_stdin();
    if ( out_scan == 1 ) { break; } // entrada correcta
    // Mensaje de error
    print_input_exception("!!Error, el valor de entrada es invalido");
  }

  return input;
}

bool get_yes_or_not( char *complete_str_message ) {
  
  assert( complete_str_message != NULL || strlen( complete_str_message ) > 0 );

  int input;
  char mss[100] = "(1 para si y 0 para no). ¿Desea ";
  strcat( mss , complete_str_message );

  while ( 1 ) {
    input = get_input_int( mss );
    if ( input >= 0 && input <= 1 ) { break; }
    print_input_exception("el numero debe ser 1 o 0!!");
  }

  return input;
}