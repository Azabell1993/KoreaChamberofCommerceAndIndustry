#ifndef PROGRAM_H_
#define PROGRAM_H_

#define _CRT_SECURE_NO_WARININGS

#define C_NRML "\033[0m"
#define C_BLCK "\033[30m"
#define C_RED  "\033[31m"
#define C_GREN "\033[32m"
#define C_YLLW "\033[33m"
#define C_BLUE "\033[34m"
#define C_PRPL "\033[35m"
#define C_AQUA "\033[36m"

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

/*INPUT LINUX API*/
#include "error_functions.h"
#include "get_num.h"

#define MAX_STUDENT_COUNT 10
#define MAX_NAME_LENGTH   10
#define PART_COUNT 10
#define PART_DATA_SIZE sizeof(int)*PART_COUNT

#define KOR 0
#define ENG 1
#define MATH 2
#define SIENCE 3
#define ETHICS 4

int i;
int j;


int TOTAL[101];
int TOTAL_SAVE[101];
float AVERAGE[101];
int LANK[101];

void Swap_Score(int score_first[], int score_second[]);
void Swap_Name(char name_first[], char name_second[]);
void Bubble_Sort(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT]);
void Input_Result(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT]);
void Result_scv(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT]);
void Lank();

FILE *fp;
FILE *tfp;

#endif
