#include "generals/sort.h"
#include <assert.h>

void bubble_sort_int ( int * array , size_t size_array , sort_type type_sort ) {
  
  assert( array != NULL && size_array > 0 );
  
  int tmp;

  if ( type_sort == ASCENDENT ) {
    for ( size_t i = 0 ; i < size_array ; i ++ )
      for ( size_t j = i ; j < size_array ; j ++ ) 
        if ( array[ j ] < array[ i ] ) {
          tmp = array[ i ];
          array[ i ] = array[ j ];
          array[ j ] = tmp;
        }
  } else { 
    for ( size_t i = 0 ; i < size_array ; i ++ )
      for ( size_t j = i ; j < size_array ; j ++ ) 
        if ( array[ j ] > array[ i ] ) {
          tmp = array[ i ];
          array[ i ] = array[ j ];
          array[ j ] = array[ i ];
        }
  }
}
