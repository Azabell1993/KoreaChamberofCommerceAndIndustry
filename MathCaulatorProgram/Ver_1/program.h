#ifndef PROGRAM_H_
#define PROGRAM_H_i
#define LIMIT_PAGE 20

#define TRUE 1
#define FALSE 0


/* include header */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

/* member */
int i;
int j;

int key;
int key_2;

int clip;
int page;
int count_index = 1;
int make_q_number;
int make_space;
int make_page;

int Que_first[1001];
int Que_second[1001];
int Que_result[1001];
float Que_result_split[1001];

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


void ft_Sum() { Que_result[i] = Que_first[i] + Que_second[i]; };
void ft_Sub() { Que_result[i] = Que_first[i] - Que_second[i]; };
void ft_Multiplication() { Que_result[i] = Que_first[i] * Que_second[i]; };
void ft_split() { Que_result_split[i] = (float)Que_first[i] / Que_second[i]; };

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

#endif

