#ifndef SORT__H
  #define SORT__H

  #include <stddef.h>

  typedef enum {
     ASCENDENT
    ,DESCENDENT
  } sort_type;

  void bubble_sort_int ( int * array , size_t size_array , sort_type type_sort );

#endif
