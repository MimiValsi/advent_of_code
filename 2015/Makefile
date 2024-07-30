CC = clang -std=c99

CFLAGS = -Imisc -D_POSIX_C_SOURCE=200809L

DFLAGS = -Wall -Wextra -Werror -Wpedantic -Wshadow -Wwrite-strings -D_POSIX_C_SOURCE=200809L

IDIR = misc
ODIR = objs
SRC = src
OPENSSL=-L/usr/local/lib/ -lssl -lcrypto
EXE = launch

OBJS = $(ODIR)/misc.o
OSRC = $(DAY).o

start: objs
build: $(DAY)
	@./launch

objs:
	mkdir -p objs/

$(DAY): $(OBJS) $(OSRC)
	@mkdir -p objs/
	$(CC) $(CFLAGS) -o $(EXE) $^

$(OSRC):
	$(CC) $(CFLAGS) -c $(SRC)/$(DAY).c -o $@

$(ODIR)/misc.o:
	$(CC) $(CFLAGS) -c $(IDIR)/misc.c -o $@

debug: $(OBJS)
	$(CC) $(DFLAGS) -o $@ $^

openssl: $(OBJS)
	$(CC) $(OPENSSL) $(CFLAGS) -o $(DAY) $^

openssl_debug: $(OBJS)
	$(CC) $(OPENSSL) $(DFLAGS) -o $(DAY) $^

valgrind:
	valgrind -s --max-stackframe=8000000 --show-leak-kinds=all --track-origins=yes --leak-check=full ./$(EXE)

valgrindTest: $(DAY)
	valgrind -s --max-stackframe=8000000 --show-leak-kinds=all --track-origins=yes --leak-check=full ./$(EXE)

cleanObjs:
	rm objs/*.o

cleanAll:
	rm objs/*.o *.o

cleanDay:
	rm *.o

.PHONY: cleanObjs cleanAll cleanDay
