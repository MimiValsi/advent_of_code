CC =clang
GCC = gcc

misc=../misc
# -I-$(misc) 

CFLAGS =-std=c17 \
	-o

OPENSSL=-L/usr/local/lib/ -lssl -lcrypto

EXE=start

build:
	@$(CC) $(CFLAGS) $(EXE) $(ARGS) ../misc/misc.c
	@./$(EXE)

DFLAGS =-std=c17 \
	-g3 \
	-Wall -Wextra -Werror -Wpedantic -Wshadow -Wwrite-strings \
	-o
debug:
	$(CC) $(DFLAGS) $(EXE) $(ARGS) ../misc/misc.c

	@./$(EXE)

openssl:
	$(CC) $(OPENSSL) $(CFLAGS) $(EXE) $(ARGS) ../misc/misc.c

	@./$(EXE)

openssl_debug:
	$(CC) $(OPENSSL) $(DFLAGS) $(EXE) $(ARGS) ../misc/misc.c

	@./$(EXE)

valgrind:
	valgrind -s --max-stackframe=8000000 --show-leak-kinds=all --track-origins=yes --leak-check=full ./$(EXE)

gcc:
	$(GCC) $(CFLAGS) $(EXE) $(ARGS) ../misc/misc.c

	@./$(EXE)

.PHONY: clean
	rm -f *.o
	rm -f ../misc/misc.o
