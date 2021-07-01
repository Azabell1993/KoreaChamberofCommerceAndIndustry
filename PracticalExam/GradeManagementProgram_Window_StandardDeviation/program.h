#ifndef PROGRAM_H_
#define PROGRAM_H_

#define _CRT_SECURE_NO_WARININGS

//리눅스용 헤더
//#define C_NRML "\033[0m"
//#define C_BLCK "\033[30m"
//#define C_RED  "\033[31m"
//#define C_GREN "\033[32m"
//#define C_YLLW "\033[33m"
//#define C_BLUE "\033[34m"
//#define C_PRPL "\033[35m"
//#define C_AQUA "\033[36m"


#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h> //리눅스용 헤더
#include <math.h> 

#define MAX_STUDENT_COUNT 10
#define MAX_NAME_LENGTH   10
#define PART_COUNT 5
#define PART_DATA_SIZE sizeof(int)*PART_COUNT

#define KOR 0
#define ENG 1
#define MATH 2
#define SIENCE 3
#define ETHICS 4

int i;
int j;


int TOTAL[101];
int SSUM;
float AVE;

int TOTAL_SAVE[101];
float AVERAGE[101];
int LANK[101];

void Swap_Score(int score_first[], int score_second[]);
void Swap_Name(char name_first[], char name_second[]);
void Bubble_Sort(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT]);
void Input_Result(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT]);
void Result_scv(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT]);

void Loop_Result(int score[][PART_COUNT]);
void Loop_Result_2(int score[][PART_COUNT]);

void Result_SSUM();
void Result_SSUM_2();

void Lank();

FILE* fp;
FILE* tfp;

double variance;
double std_deviation;

double variance_2;
double std_deviation_2;

void Loop_Result(int score[][PART_COUNT])
{
	for(int i=0; i<MAX_STUDENT_COUNT; i++)
	{
		variance = 0;
		variance = variance + (
								(((score[i][0]) - AVERAGE[i]) * ((score[i][0]) - AVERAGE[i])) +
								(((score[i][1]) - AVERAGE[i]) * ((score[i][1]) - AVERAGE[i])) +
								(((score[i][2])-AVERAGE[i]) * ((score[i][2])-AVERAGE[i])) +
								(((score[i][3])-AVERAGE[i]) * ((score[i][3])-AVERAGE[i])) + 
								(((score[i][4])-AVERAGE[i]) * ((score[i][4])-AVERAGE[i]))
							  );
							  
		variance = variance / PART_COUNT;
		std_deviation = sqrt(variance);
							  
		fprintf(tfp,"%d번째 분산 , %.3lf,  표준 편차 , %.3f\n",i+1, variance, std_deviation);
	}
}

void Loop_Result_2(int score[][PART_COUNT])
{
	for(int i=0; i<MAX_STUDENT_COUNT; i++)
	{
		variance_2 = 0;
		variance_2 = variance_2 + (
								(((score[i][0]) - AVERAGE[i]) * ((score[i][0]) - AVERAGE[i])) +
								(((score[i][1]) - AVERAGE[i]) * ((score[i][1]) - AVERAGE[i])) +
								(((score[i][2])-AVERAGE[i]) * ((score[i][2])-AVERAGE[i])) +
								(((score[i][3])-AVERAGE[i]) * ((score[i][3])-AVERAGE[i])) + 
								(((score[i][4])-AVERAGE[i]) * ((score[i][4])-AVERAGE[i]))
							  );
							  
		variance_2 = variance_2 / PART_COUNT;
		std_deviation_2 = sqrt(variance);
							  
		printf(fp,"%d번째 분산 , %.3lf,  표준 편차 , %.3f\n",i+1, variance_2, std_deviation_2);
	}
}


#endif
