# Tetris

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
