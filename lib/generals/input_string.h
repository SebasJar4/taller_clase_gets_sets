#ifndef INPUT_STRING_lib
#define INPUT_STRING_lib

#include<stdbool.h>
#include<stdlib.h>
/**
 * Esta funcion recive un array tipo char * str y el tamaño del array que se llenara, se ingresaran datos hasta que se llene...
 */

bool fill_array_of_stin ( char * arr , const size_t size_arr ); /* Esta funcion rellena el array segun el tamaño del stdin, usa en el fondo get_str_stdin y su retorno es true para todo salio bien y false para hubo un error */ 


char * get_str_stdin (); // Esta funcion toma el input del stdin hasta el primer '\n' que encuentre
#endif