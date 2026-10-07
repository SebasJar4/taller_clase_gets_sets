#ifndef INPUT_FUNCTIONS
#define INPUT_FUNCTIONS

#include <stdbool.h>
#include <stdarg.h>
#include <assert.h>
#include <stdlib.h>

void print_input_exception( const char * format , ...);

void limpieza_stdin( void );
void press_enter_to_continue( void );
int get_input_int ( char * complete_str_message );
bool get_yes_or_not( char * complete_str_message );
double get_input_double ( char * complete_str_message );

#endif
