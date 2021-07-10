#ifndef PROGRAM_H_
#define PROGRAM_H_

#define _CRT_SECURE_NO_WARININGS

#define C_NRML "\033[0m"
#define C_BLACK "\033[30m"
#define C_RED	"\033[31m"
#define C_GREN 	"\033[32m"
#define C_YLLWW "\033[33m"
#define C_BLUE  "\033[34m"
#define C_PRPL  "\033[35m"
#define C_AQUA  "\033[36m"

/* include header */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include <malloc.h>
#include <stddef.h>
#include <termios.h>
#include <stdbool.h>

#include "include/error_functions.h"
#include "include/get_num.h"
#include "include/tlpi_hdr.h"


#define WIDTH 	25
#define HEIGHT 	24
#define TOPLSITMAXLINELENGTH 34

char piece;
char *name;

int level;
int score;
int showtext=1;
int next;
int shownext = 1;
int end;
int clrlines = 0;
int startlevel;
int dropped = 0;

char key;

char left[HEIGHT][WIDTH] = {0};
char center[HEIGHT][WIDTH] = {0};
char right[HEIGHT][WIDTH] = {0};

int fixedpoint[2] = {0};

#define MOVL 'q'
#define MOVR 'e'
#define ROTA 'w'
#define DROP 'a'
#define RSET 'l'
#define SNXT 'z'
#define STXT 'c'
#define EXT  'k'
#define TPLS 't'

#define NEMO 'n'
#define ONE 'o'

#define SCORE (100*cleard+75*(cleard/2)+125*(cleard/3)+150*(cleard/4))* level
#define DROPINTERVAL (DELAY/1000) * ((300 - level*13)/5)
#define DELAY 7777
#define MAXLEVEL 30
#define LINESFORLVLUP 10


int linux_console();


int linux_console(void)
{
    struct termios oldt, newt;
    int ch;

    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;

    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    ch = getchar();

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

    return ch;
}


void shoe_next();
void updatescrn();
void updatescore();
void toplist();
void addscore();
int  gameover();
void checkclr();
void initpiece();
void rotate();
void moveleft();
void moveright();
int movedown();
void init();
void updatelevel();
void setkeybint();
int game();
int Enter;

void show_logo();


void concept_1();
void concept_2();
void concept_3();
void concept_4();
int  Key_setting();

struct timeval t1, t2;

char TetrominoI[2][WIDTH] = {"<! . . . . . . . . . .!>",
                             "<! . . .[][][][] . . .!>"};

char TetrominoJ[2][WIDTH] = {"<! . . .[] . . . . . .!>",
                             "<! . . .[][][] . . . .!>"};

char TetrominoL[2][WIDTH] = {"<! . . . . .[] . . . .!>",
                             "<! . . .[][][] . . . .!>"};

char TetrominoO[2][WIDTH] = {"<! . . . .[][] . . . .!>",
                             "<! . . . .[][] . . . .!>"};

char TetrominoS[2][WIDTH] = {"<! . . . .[][] . . . .!>",
                             "<! . . .[][] . . . . .!>"};

char TetrominoT[2][WIDTH] = {"<! . . . .[] . . . . .!>",
							 "<! . . .[][][] . . . .!>"};

char TetrominoZ[2][WIDTH] = {"<! . . .[][] . . . . .!>",
                             "<! . . . .[][] . . . .!>"};

#endif
