#ifndef DATA_sTRUCts
#define DATA_sTRUCts

#define CODE_SIZE 10
#define NAME_SIZE 12
#define LAST_NAME_SIZE 12
#define CARRER_SIZE 15
#define FACULTY_SIZE 20

typedef struct { // el mas 1 es para el '\0'
  char *code;
  char *name;
  char *last_name;
  char *carrer;
  int sem;
  char *faculty; 
} Student;

#endif