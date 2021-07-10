
CC=gcc
CFLAGS= -Wformat -W -Wextra -Werror -Wall -I ./include/ 
PATH_LIB= ./include/
SRCS = main.c
LIBS=-lncurses
OBJ = main.o \
	  $(PATH_LIB)error_functions.o
NAME= main

.PHONY: depend clean

all: $(NAME)
	@echo  '$(NAME)' has been compiled. You can play the game through '$(NAME)'. 

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
	

clean:
	$(RM) *.o *~ $(NAME) $(PATH_LIB)*.o
	rm -rf toplist
#


