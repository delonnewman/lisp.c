#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum {
  TYPE_INT    = 0,
  TYPE_BOOL   = 1,
  TYPE_FLOAT  = 2,
  TYPE_CHAR   = 3,
  TYPE_STRING = 4,
  TYPE_SYMBOL = 5,
  TYPE_CONS   = 6,
  TYPE_ARRAY  = 7,
  TYPE_MAP    = 8,
};

typedef struct Object {
  int type;
  long int_val;
  double float_val;
  char char_val;

  // strings, symbols
  char* str_val;

  // collections
  size_t count;

  size_t* array_ref;

  // list car and cdr
  struct Object* car;
  struct Object* cdr;
} Object;

Object* object_allocate();
void object_destroy(Object* object);
void object_copy(Object* target, Object* source);

Object* object_integer(long value);
Object* object_char(char value);
Object* object_float(double value);
Object* object_string(char* value);
Object* object_symbol(char* value);
Object* object_true();
Object* object_false();

Object* list_empty();
Object* list_cons(Object* value, Object* list);
Object* list_car(Object* list);
Object* list_cdr(Object* list);
void list_print(Object* list);
bool is_list(Object* list);

Object* make_array(size_t size);
Object* array_at(Object* array, int index);
void array_set(Object* array, int index, Object* value);
void array_print(Object* array);
bool is_array(Object* array);

size_t count(Object* list);
bool is_collection(Object* list);

bool is_equal(Object* obj1, Object* obj2);
bool is_zero(Object* obj);
bool is_empty(Object* list);
bool is_false(Object* obj);
bool is_true(Object* obj);
bool is_integer(Object* obj);
bool is_float(Object* obj);
bool is_number(Object* obj);

char* type_name(Object* obj);
void print(Object* obj);
void say(Object* obj);
