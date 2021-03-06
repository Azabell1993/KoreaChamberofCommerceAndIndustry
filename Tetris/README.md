# **Tetris Game Program**  

***File Tree***  
===============  

```c
.
├── game_install.sh   
├── include
│   ├── ename.c.inc
│   ├── error_functions.c
│   ├── error_functions.h
│   ├── get_num.c
│   ├── get_num.h
│   └── tlpi_hdr.h
├── logo.h
├── main.c
├── Makefile
├── move_down.h
├── move_left.h
├── move_right.h
├── move_rotate.h
├── Print_screen.h
├── program.h
├── README.md
└── settings.h  
```  

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
gcc -Wformat -W -Wextra -Werror -Wall -I ./include/  -o main main.o -lncurses ./include/error_functions.o 
main has been compiled. You can play the game through main.
```  

**Or play the game with an automated system**  

```c
$ ./game_install.sh
```  

```c
Mr/Ms. : (USER NAME)
Hello! Nice to meet you!

Running the Makefile
gcc -c -o ./include/error_functions.o  ./include/error_functions.c
gcc -Wformat -W -Wextra -Werror -Wall -I ./include/    -c -o main.o main.c
ar rc main 
gcc -Wformat -W -Wextra -Werror -Wall -I ./include/  -o main main.o -lncurses ./include/error_functions.o
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

(Program.h)
=========================================
![program](https://user-images.githubusercontent.com/75885992/125165420-53a32480-e186-11eb-8c6f-593e9b64cd1f.png)  

(Before putting "$(OBJ)" in "Makefile")
=========================================

![NULL](https://user-images.githubusercontent.com/75885992/125165668-7550db80-e187-11eb-892e-b155e79d3b17.png)  

(ETC / screencapture)
=========================================


![linux_console](https://user-images.githubusercontent.com/75885992/125164581-8f3bef80-e182-11eb-8fb4-4e58d1fead8c.png)  

![Tetris_Makefile](https://user-images.githubusercontent.com/75885992/125164061-ceb50c80-e17f-11eb-92d3-c21a53c136a7.png)  

![make_run](https://user-images.githubusercontent.com/75885992/125164127-323f3a00-e180-11eb-8028-6f603e2ef575.png)  

![gameins](https://user-images.githubusercontent.com/75885992/125180315-18394200-e1e8-11eb-9284-28a172f08262.png)  

![run_sh](https://user-images.githubusercontent.com/75885992/125164438-bcd46900-e181-11eb-9fb9-a9691929e282.png)  

![ls](https://user-images.githubusercontent.com/75885992/125164168-6a467d00-e180-11eb-8f20-97a922662c0d.png)  

![te1](https://user-images.githubusercontent.com/75885992/125160450-70caf980-e16c-11eb-87ce-5a5246e0e67e.png)  



