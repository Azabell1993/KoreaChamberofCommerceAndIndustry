# **Tetris Game Program**  

***File Tree***  
===============  

|/////// **include**  
|///////|-- ename.c.inc  
|///////|-- error_functions.c  
|///////|-- error_functions.h  
|///////|-- get_num.c  
|///////|-- get_num.h  
|///////|-- tlpi_hdr.h  
|-- game_install.sh   
|-- logo.h  
|-- Makefile  
|-- move_down.h  
|-- move_left.h  
|-- move_right.h  
|-- move_rotate.h  
|-- Print_screen.h  
|-- program.h  
|-- settings.h  

**Where is the use at 'include' folder**  

```c
  if(!(f=fopen("toplist", "r")) == '\0')
  {
	  errExit(" File open Error \n");
  }  
```  

***Makefile***  
  
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
	$(CC) $(CFLAGS) -o $(NAME) $(MOBJ) $(LIBS) $(OBJ)

clean:
	$(RM) *.o *~ $(NAME) $(PATH_LIB)*.o
	rm -rf toplist
#
```  

***HOW TO PLAY THE GAME***  
===============  

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

**Or play the game with an automated system**  

```c
$ ./game_install.sh
```  

```c
Mr/Mrs. : (USER NAME)
Hello! Nicd to meet you!

Running the Makefile
gcc -c -o ./include/error_functions.o  ./include/error_functions.c
gcc -Wformat -W -Wextra -Werror -Wall -I ./include/    -c -o main.o main.c
ar rc main 
gcc -Wformat -W -Wextra -Werror -Wall -I ./include/  -o main main.o -lncurses
main has been compiled. You can play the game through main.
saved toplist

latest estimate User : (USER NAME)
(SHOW THE FILE)
 
Open the toplist log
(SHOW THE FILE)
```  

  
**Result**    
(make first, make stap)  
```c
$ ls
game_install.sh  logo.h  main.c  Makefile     move_left.h   move_rotate.h   program.h  settings.h
include          main    main.o  move_down.h  move_right.h  Print_screen.h  README.md  toplist
```  
(.sh step)  
```c
game_install.sh  main    Makefile     move_right.h    program.h   toplist_saevd.text
include          main.c  move_down.h  move_rotate.h   README.md   whoami_saved.text
logo.h           main.o  move_left.h  Print_screen.h  settings.h  whoami.text
```  

**play the main** 
  
```c
$ ./main
```  

![Tetris_Makefile](https://user-images.githubusercontent.com/75885992/125164061-ceb50c80-e17f-11eb-92d3-c21a53c136a7.png)  


![installsh](https://user-images.githubusercontent.com/75885992/125161034-78d86880-e16f-11eb-9973-f0d976f8b85b.png)  


![make step](https://user-images.githubusercontent.com/75885992/125160990-4dee1480-e16f-11eb-81de-3acacf2d3b91.png)  

![gameinstallsh](https://user-images.githubusercontent.com/75885992/125160440-61e44700-e16c-11eb-81a4-4169aab04ede.png)  

![te1](https://user-images.githubusercontent.com/75885992/125160450-70caf980-e16c-11eb-87ce-5a5246e0e67e.png)  

![gameplay](https://user-images.githubusercontent.com/75885992/125160434-5e50c000-e16c-11eb-959b-500337b16245.png)  

![name](https://user-images.githubusercontent.com/75885992/125160452-745e8080-e16c-11eb-9a52-659fe1159449.png)  

![name2](https://user-images.githubusercontent.com/75885992/125160454-758fad80-e16c-11eb-9b4b-9ab9af841e15.png)  

![play](https://user-images.githubusercontent.com/75885992/125160457-7a546180-e16c-11eb-84b2-f4874b8295ad.png)  

![gameover](https://user-images.githubusercontent.com/75885992/125160558-272ede80-e16d-11eb-86a0-81806845b2f5.png)  


