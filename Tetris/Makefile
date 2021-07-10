#
CC=gcc
CFLAGS= -Wformat -W -Wextra -Werror -Wall -I ./include/ 
COMPILE = $(CC) $(CFLAGS)
PATH_LIB= ./include/
SRCS = main.c
LIBS=-lncurses
MOBJ= main.o
OBJ = $(PATH_LIB)error_functions.o 
ER= $(PATH_LIB)error_functions.c
NAME= main

.PHONY: depend clean

all: $(NAME)
	@echo  '$(NAME)' has been compiled. You can play the game through '$(NAME)'. 

first: 
	$(CC) -c -o $(OBJ) $(ER)

$(NAME): $(MOBJ)
	ar rc $(NAME) 
	$(CC) $(CFLAGS) -o $(NAME) $(MOBJ) $(LIBS) $(OBJ)

clean:
	$(RM) *.o *~ $(NAME) $(PATH_LIB)*.o
	rm -rf toplist
#


