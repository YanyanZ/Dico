CC=gcc
CFLAGS=-W -Wall -pedantic -std=c99
LDFLAGS=
EXE=dico

SRC=sources/main.c
OBJ=$(SRC:.c=.o)

all: $(EXE)

dico : $(OBJ)
	$(CC) -o $@ $^ $(LDFAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -f sources/*.o $(EXE)
