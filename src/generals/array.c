#include "generals/array.h"
#include "generals/input_functions.h"

void get_int_vector ( int * vector , size_t size ) {
  assert( ( vector != NULL || "Vector nulo" ) && ( size > 0 || "size invalido" ) );
  char buffer[ 100 ];

  for ( size_t i = 0 ; i < size ; i ++ ) {
    sprintf( buffer , "el numero %lu de %lu" , i + 1 , size );
    vector[ i ] = get_input_int( buffer );
  }
}

void get_int_array ( size_t filas , size_t columnas, int array[filas][columnas] ) {
  assert( ( array != NULL || "Vector nulo" ) && ( filas > 0 || "filas invalido" ) && ( columnas > 0 || "columnas invalida") );
  char buffer[ 150 ];
  for ( size_t f = 0 ; f < filas ; f ++ ) {
    for ( size_t c = 0 ; c < columnas ; c ++ ) {
      sprintf( buffer , "el valor de la fila %lu y la columna %lu de %lu y %lu" , f + 1 , c + 1 , filas , columnas );
      array[ f ][ c ] = get_input_int( buffer );
    }
  }
}

long get_int_adj_of_array ( size_t filas , size_t columnas , int array[filas][columnas] ) {
  assert( ( array != NULL || "array nulo ") && ( filas > 0 || "filas invalidas" ) && ( columnas > 0 || "columnas invalidas ") );
  long input = 0;
  for ( size_t f = 0 ; f < filas ; f ++ ) 
    for ( size_t c = 0 ; c < columnas ; c ++ )
      input += array[ f ][ c ];
  return input; 
}

void print_int_array ( size_t filas , size_t columnas , int array[filas][columnas] ) {
  assert( ( array != NULL || "array nulo ") && ( filas > 0 || "filas invalidas" ) && ( columnas > 0 || "columnas invalidas ") );
    for ( size_t f = 0 ; f < filas ; f ++ ) {
    printf(" | ");
    for ( size_t c = 0 ; c < columnas ; c ++ ) {
      printf("%d " , array[f][c]);
    }
    printf("|\n");
  }
}

void init_int_array_in_0 ( size_t filas , size_t columnas , int array[filas][columnas] ) {
  assert( ( array != NULL || "array nulo ") && ( filas > 0 || "filas invalidas" ) && ( columnas > 0 || "columnas invalidas ") );
  for ( size_t f = 0 ; f < filas ; f ++ )
    for ( size_t c = 0 ; c < columnas ; c ++ )
      array[ f ] [ c ] = 0;
}