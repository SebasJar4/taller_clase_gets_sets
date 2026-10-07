#include"specifics/gets_sets_student.h"
#include"generals/input_string.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<regex.h>
#include<string.h>

bool validate_data ( char * exp , char * str ) {
  regex_t regex;
  int res = regcomp( &regex, exp , REG_EXTENDED );

  if (res != 0) {
      printf("Error al compilar la regex.\n");
      return 1;
  }

  return regexec( &regex , str , 0 , NULL , 0 ) == 0;
}

bool validate_code_data ( char * str ) {
  return validate_data( "^[a-zA-Z0-9_\\-\\+!@#\\$.,]+$" , str );
}

bool validate_carrer_or_faculty ( char * str ) {
  return validate_data( "^[a-zA-ZáéíóúÁÉÍÓÚñÑ]+( [a-zA-ZáéíóúÁÉÍÓÚñÑ]+)*$" , str );
}

bool validate_alphabeth ( char * str ) {
  return validate_data( "^[a-zA-ZáéíóúÁÉÍÓÚñÑ]+$" , str );
}

char * get_code() {
  
  char * tmp;
  char * str = malloc( CODE_SIZE );
  while ( true ) {

    printf("@Ingrese el codigo del estudiante (tiene que tener maximo %d caracteres puede poner letras, numeros o \"_-+!@#$.,\") > " ,  CODE_SIZE );
    tmp = get_str_stdin();

    if ( validate_code_data( tmp ) && strlen(tmp) <= CODE_SIZE ) break;
    
    print_input_exception("La entrada '%s', solo puede contener letras, numeros o '_-+!@#$.,' y maximo %lu caracteres" , tmp , CODE_SIZE );
    free( tmp );

  }

  // copiamos hasta donde se pueda
  for ( int i = 0 ; i < CODE_SIZE; i ++ ) {
    str[ i ] = tmp[ i ];
    if ( tmp[ i ] == '\0' ) break;
  }

  free( tmp );

  str[ CODE_SIZE ] = '\0';
  return str;
}

char * get_name( ) {
  char * tmp;
  char * str = malloc( NAME_SIZE );
  while ( true ) {

    printf("@Ingrese el nombre del estudiante (tiene que tener maximo %d caracteres puede poner letras solamente) > " ,  NAME_SIZE );
    tmp = get_str_stdin();

    if ( validate_alphabeth( tmp ) && strlen(tmp) <= NAME_SIZE ) break;

    print_input_exception("La entrada '%s', solo puede contener letras y %lu" , tmp , CODE_SIZE );
    free( tmp );

  }

  // copiamos hasta donde se pueda
  for ( int i = 0 ; i < NAME_SIZE; i ++ ) {
    str[ i ] = tmp[ i ];
    if ( tmp[ i ] == '\0' ) break;
  }

  free( tmp );
  
  str[ NAME_SIZE ] = '\0';
  return str;
}

char * get_last_name( ) {
  char * tmp;
  char * str = malloc( LAST_NAME_SIZE );
  while ( true ) {

    printf("@Ingrese el apellido del estudiante (tiene que tener maximo %d caracteres puede poner letras solamente) > " ,  LAST_NAME_SIZE );
    tmp = get_str_stdin();

    if ( validate_alphabeth( tmp ) && strlen(tmp) <= LAST_NAME_SIZE ) break;

    print_input_exception("La entrada '%s', solo puede contener letras y %lu caracteres" , tmp , LAST_NAME_SIZE );
    free( tmp );

  }

  // copiamos hasta donde se pueda
  for ( int i = 0 ; i < LAST_NAME_SIZE; i ++ ) {
    str[ i ] = tmp[ i ];
    if ( tmp[ i ] == '\0' ) break;
  }

  free( tmp );
  
  str[ LAST_NAME_SIZE ] = '\0';
  return str;
}

int get_semester( ) {
  int input; 
  while ( true ) {
    input = get_input_int("el semestre del estudiante");
    if ( input > 0 ) break;
    limpieza_stdin();
    print_input_exception( "La entrada %d no puede ser <= 0..." , input );
  }

  return input;
}

char * get_carrer( ) {
  char * tmp;
  char * str = malloc( CARRER_SIZE );
  
  while ( true ) {

    printf("@Ingrese la carrera del estudiante (tiene que tener maximo %d caracteres puede poner letras solamente y espacio) > " ,  CARRER_SIZE );
    tmp = get_str_stdin();

    if ( validate_carrer_or_faculty( tmp ) && strlen(tmp) <= CARRER_SIZE ) break;

    print_input_exception("La entrada '%s', solo puede contener letras y un espacio. Hasta %lu caracteres" , tmp , CARRER_SIZE );
    free( tmp );

  }

  // copiamos hasta donde se pueda
  for ( int i = 0 ; i < CARRER_SIZE; i ++ ) {
    str[ i ] = tmp[ i ];
    if ( tmp[ i ] == '\0' ) break;
  }

  free( tmp );
  
  str[ CARRER_SIZE ] = '\0';
  return str;
}

char * get_faculty( ) {
  char * tmp;
  char * str = malloc( FACULTY_SIZE );
  
  while ( true ) {

    printf("@Ingrese la facultad del estudiante (tiene que tener maximo %d caracteres puede poner letras y espacio solamente) > " ,  FACULTY_SIZE );
    tmp = get_str_stdin();

    if ( validate_carrer_or_faculty( tmp ) && strlen(tmp) <= FACULTY_SIZE ) break;

    print_input_exception("La entrada '%s', solo puede contener letras y espacio. Hasta %lu caracteres" , tmp , FACULTY_SIZE );
    free( tmp );

  }

  // copiamos hasta donde se pueda
  for ( int i = 0 ; i < FACULTY_SIZE ; i ++ ) {
    str[ i ] = tmp[ i ];
    if ( tmp[ i ] == '\0' ) break;
  }

  free( tmp );
  
  str[ FACULTY_SIZE ] = '\0';
  return str;
}

Student get_student() {
  Student student;
  student.code = get_code();
  student.name = get_name();
  student.last_name = get_last_name();
  student.carrer = get_carrer();
  student.faculty = get_faculty();
  student.sem = get_semester();
  return student;
}

bool set_code( Student * student );
bool set_name( Student * student );
bool set_last_name( Student * student );
bool set_carrer( Student * student );
bool set_semester( Student * student );
bool set_faculty( Student * student );

bool set_all_of_student( Student * student ) {
  student->code = get_code();
  student->name = get_name();
  student->last_name = get_last_name();
  student->carrer = get_carrer();
  student->faculty = get_faculty();
  student->sem = get_semester();
  return true;
}

void print_student( Student * student ) {
  printf(
    "Estudiante: \n - Codigo: %s \n - Nombre: %s \n - Apellido: %s \n - Carrera: %s \n - Facultad: %s \n - Semestre %d \n" 
    , student->code 
    , student->name 
    , student->last_name 
    , student->carrer 
    , student->faculty 
    , student->sem 
  );
}