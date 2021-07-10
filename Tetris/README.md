# Tetris

Makefile
```c
#
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
	$(RM) *.o *~ $(NAME)
#
```  


```c
$ make
```  

```c
gcc -Wformat -W -Wextra -Werror -Wall -I ./include/    -c -o main.o main.c
ar rc main main.o ./include/error_functions.o 
gcc -Wformat -W -Wextra -Werror -Wall -I ./include/  -o main main.o ./include/error_functions.o -lncurses
main has been compiled. You can play the game through main.
```  
  
```c
$ ls
game_install.sh  logo.h  main.c  Makefile     move_left.h   move_rotate.h   program.h  settings.h
include          main    main.o  move_down.h  move_right.h  Print_screen.h  README.md  toplist
```  

play the main  
```c
$ ./main
```  
