CC = clang

CFLAGS = -std=c17\
	-Wall -Wextra -Werror -Wpedantic\
	-o

build:
	@$(CC) $(CFLAGS) start $(ARGS) ../misc/misc.c
	@./start

.PHONY: clean
	rm -f *.o ../misc/misc.o
