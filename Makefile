.POSIX:

CC      = cc
CFLAGS  = -std=c99 -Wall -Wextra -Wno-missing-field-initializers
LDFLAGS =
LDLIBS  =
SRC     = src
NAME    = sparrow

all: $(NAME)

clean:
	rm -f $(NAME) $(NAME).o
	rm -f test/list_test$(EXE)

$(NAME).o:
	$(CC) -c $(CFLAGS) -o $@ $(SRC)/$(NAME).c

lisp$(EXE): $(NAME).o
	$(CC) $(CFLAGS) -o $@ $(SRC)/main.c $(NAME).o $(LDLIBS)

run: $(NAME)
	./$(NAME)$(EXE)

test/list_test$(EXE): $(NAME).o
	$(CC) $(CFLAGS) -I$(SRC) -o $@ test/list_test.c $(NAME).o $(LDLIBS)

test/equal_test$(EXE): $(NAME).o
	$(CC) $(CFLAGS) -I$(SRC) -o $@ test/equal_test.c $(NAME).o $(LDLIBS)

test/array_test$(EXE): $(NAME).o
	$(CC) $(CFLAGS) -I$(SRC) -o $@ test/array_test.c $(NAME).o $(LDLIBS)

test: test/list_test$(EXE) test/equal_test$(EXE) test/array_test$(EXE)
	./test/list_test$(EXE)
	./test/equal_test$(EXE)
	./test/array_test$(EXE)

.PHONY: all clean run test
