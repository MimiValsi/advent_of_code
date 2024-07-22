CC = clang

CFLAGS = -std=c99 -Imisc

EXE = launch
IDIR = misc

objects = ./src/day1.o $(IDIR)/misc.o

$(EXE): $(objects)
	$(CC) $(CFLAGS) -o $@ $^

./src/day1.o:
	$(CC) $(CFLAGS) -c ./src/day1.c -o src/day1.o

$(IDIR)/misc.o:

	$(CC) $(CFLAGS) -c $(IDIR)/misc.c -o $(IDIR)/misc.o

valgrind:
	valgrind -s --max-stackframe=8000000 --show-leak-kinds=all --track-origins=yes --leak-check=full ./$(EXE)
