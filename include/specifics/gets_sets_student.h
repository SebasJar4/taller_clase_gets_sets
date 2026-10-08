#ifndef GET_Inputs_H
  #define GET_Inputs_H

  #include"data_structs.h"
  #include"generals/input_string.h"
  #include"generals/input_functions.h"
  #include<stdbool.h>

  char * get_code( );
  char * get_name( );
  char * get_last_name( );
  char * get_carrer( );
  int get_semester( );
  char * get_faculty( );

  Student get_student();

  bool set_code( Student * student );
  bool set_name( Student * student );
  bool set_last_name( Student * student );
  bool set_carrer( Student * student );
  bool set_semester( Student * student );
  bool set_faculty( Student * student );
  bool set_all_of_student( Student * student );
  bool set_all_of_student_without_code ( Student * student );

  void print_student( Student * student );

#endif