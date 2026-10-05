#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

bool valid_characters_for_ignorin_initial_spaces ( int c ) {
  char invalid_char[] = { ' ' , '\t' , '\0' };
  for ( int i = 0 ; i < (sizeof( invalid_char ) / sizeof( invalid_char[0] )) ; i ++ ) 
    if ( c == invalid_char[ i ] ) return false;  
  return true;
}

char * get_str_stdin () {
  // creamos un array que crecera dinamicamente
  size_t capacity = 30;
  char *str = malloc( capacity ); // recervamos memoria en el heap
  
  if ( str == NULL ) { // si no se pudo error...
    fprintf( stderr , "!Error: el programa no logro recervar el malloc... ");
    exit( EXIT_FAILURE );
  }


  // Leer caracteres uno a uno hasta encontrar '\n' o EOF
  int index = 0;
  while (true) {
    int current = getc(stdin); // Usamos int para detectar EOF correctamente

    if (current == EOF || current == '\n') {
      break; // Salimos al presionar Enter o si ocurre un fin de archivo
    }

    if ( (index + 1) >= capacity ) { // si excede la capadidad incrementamos mas el array
      capacity *= 1.5;
   
      char *tmp = realloc( str , capacity ); // pedimos el incremento
      if ( tmp == NULL ) { // si no error
        fprintf( stderr , "!!Error, el programa no pudo incrementar el tama;o del array" );
        free( str );
        exit( EXIT_FAILURE );
      }
      // si si, lo guardamos en el str (la variable temporal muere aca)...
      str = tmp;
    }
    
    // le metemos el valor a el array...
    str[index] = (char)current;
    index++; // incrementamos el index que guardara el array
  }

  // le ponemos el delimitador
  str[ index ] = '\0';
  return str; // retornamos el puntero ( no desaparecera ya que esta en el heap y no en el stack)
}


bool fill_array_of_stin ( char * arr , const size_t size_arr ) {

  assert( ( arr != NULL ) && ( size_arr > 0 ) );

  char *tmp = get_str_stdin();

  int index = 0;
  for ( int i = 0 ; i < strlen( tmp ) ; i ++ ) {
    arr[ index++ ] = tmp[ i ];
    if ( index >= size_arr ) break;
  }

  arr[ index ] = '\0';

  return true;
}
