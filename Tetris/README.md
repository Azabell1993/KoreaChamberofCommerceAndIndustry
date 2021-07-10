# Tetris

**Makefile**  
  
```c
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
	$(CC) $(CFLAGS) -o $(NAME) $(MOBJ) $(LIBS)

clean:
	$(RM) *.o *~ $(NAME) $(PATH_LIB)*.o
	rm -rf toplist
#
```  

**First Step**  


```c
$ make fist
```  

```c
gcc -c -o ./include/error_functions.o  ./include/error_functions.c
```  


**Second Step**

```c
$ make
```  

```c
gcc -Wformat -W -Wextra -Werror -Wall -I ./include/    -c -o main.o main.c
ar rc main 
gcc -Wformat -W -Wextra -Werror -Wall -I ./include/  -o main main.o -lncurses
main has been compiled. You can play the game through main.
```  
  
**Result**    

```c
$ ls
game_install.sh  logo.h  main.c  Makefile     move_left.h   move_rotate.h   program.h  settings.h
include          main    main.o  move_down.h  move_right.h  Print_screen.h  README.md  toplist
```  

**play the main** 
  
```c
$ ./main
```  
