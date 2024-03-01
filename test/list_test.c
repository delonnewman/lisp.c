#include "lisp.h"
#include <assert.h>

void test_empty() {
  Object* list = list_empty();

  assert(is_empty(list));
}

void test_empty_count() {
  Object* list = list_empty();

  assert(is_zero(list_count(list)));
}

void test_cons() {
  Object* list = list_empty();
  list = list_cons(object_integer(1), list);

  assert(is_equal(list_car(list), object_integer(1)));
}

int main() {
  test_empty();
  test_empty_count();
  test_cons();

  return EXIT_SUCCESS;
}
