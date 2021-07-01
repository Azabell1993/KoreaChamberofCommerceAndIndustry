#ifndef PROGRAM_H_
#define PROGRAM_H_
#define LIMIT_PAGE 20

#define C_NRML "\033[0m"
#define C_BLCK "\033[30m"
#define C_RED  "\033[31m"
#define C_GREN "\033[32m"
#define C_YLLW "\033[33m"
#define C_BLUE "\033[34m"
#define C_PRPL "\033[35m"
#define C_AQUA "\033[36m"

/* include header */
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

#include "error_functions.h"
#include "get_num.h"

#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif

typedef enum {
	FALSE,
	TRUE
} Boolean;

#define min(m,n) ((m) < (n) ? (m):(n))
#define max(m,n) ((m) > (n) ? (m):(n))

#if defined(__sgi)
typedef int socklen_t;
#endif

#if defined(__sun)
#include <sys/file.h>
#endif

#if ! defined(O_ASYNC) && defined(FASYNC)
#define O_ASYNC FASYNC
#endif

#if defined(MAP_ANON) && ! defined(MAP_ANONVMOUS)
#define MAP_ANOVMOUS MAP_ANON

#endif

#if ! defined(O_SYNC) && defined(O_FSYNC)
#define O_SYNC O_FSYNC
#endif

#if defined(__FreeBSD__)

#define sival_int sigval_int
#define sival_ptr sigval_ptr
#endif

#endif



/* open */
#include <sys/stat.h>
#include <fcntl.h>


/* member */
int i;
int j;

char key;
int key_2;

int count;
int clip;
int page;
int state;
int count_index = 1;
int make_q_number;
int make_space;
int make_page;

int correct_count = 0;
int ng_count = 0;

int infocount;

int Que_first[1001];
int Que_second[1001];
int Que_result[1001];
float Que_result_split[1001];

int int_answer[1001];
float float_answer[1001];

/* function */
int linux_console();

void ft_Choose();
void ft_make_qes();
void ft_Sum();
void ft_Sub();
void ft_Multiplication();
void ft_split();
void ft_Result();
void ft_Display_output_ques_result();
void ft_show_result_list();
int  linux_console();

void ft_putchar(char c);
void ft_sumbit();
void ft_sumbit_check();

void ft_Sum() { Que_result[i] = Que_first[i] + Que_second[i]; };
void ft_Sub() { Que_result[i] = Que_first[i] - Que_second[i]; };
void ft_Multiplication() { Que_result[i] = Que_first[i] * Que_second[i]; };
void ft_split() { Que_result_split[i] = (float)Que_first[i] / Que_second[i]; };

int open(const char *pathname, int flags, ... /*mode_t mode*/);



/*window conio linux version */
int linux_console()
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

FILE *fp;


