#ifndef MY_ARRAY_
#define MY_ARRAY_

#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

void get_int_vector ( int * vector , size_t size );
void get_int_array ( size_t filas , size_t columnas, int array[filas][columnas] );
void print_int_array ( size_t filas , size_t columnas , int array[filas][columnas] );
long get_int_adj_of_array ( size_t filas , size_t columnas , int array[filas][columnas] );
void init_int_array_in_0 ( size_t filas , size_t columnas , int array[filas][columnas] );

#endif