CC = clang

CFLAGS = -std=c17\
	-Wall -Wextra -Werror -Wpedantic\
	-o

EXE = start

build:
	@$(CC) $(CFLAGS) $(EXE) $(ARGS) ../misc/misc.c
	@./$(EXE)

valgrind:
	valgrind -s --show-leak-kinds=all --track-origins=yes --leak-check=full ./$(EXE)

.PHONY: clean
	rm -f *.o
	rm -f ../misc/misc.o
