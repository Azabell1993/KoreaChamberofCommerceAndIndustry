#
CC=gcc

CFLAGS=-Wall -pedantic -g

INCLUDES=

LFLAGS=

LIBS=-lncurses

SRCS=tetris.c

OBJS=$(SRCS:.c=.o)

NAME=tetris

.PHONY: depend clean

all: $(NAME)
	@echo  $(NAME) has been compiled.

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

compile_exe : tetris.o error_functions.o
	gcc -o compile_exe tetris.o error_functions.o

error_functions.o : error_functions.c
	gcc -c -o error_functions.o error_functions.c

tetris.o : tetris.c
	gcc -c -o tetris.o tetris.c

clean:
	$(RM) *.o *~ $(NAME)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

#
