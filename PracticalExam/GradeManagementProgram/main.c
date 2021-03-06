#include "program.h"
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
void Swap_Score(int score_first[], int score_second[])
{
	int temp[PART_COUNT];

	memcpy(temp, score_first, PART_DATA_SIZE);
	memcpy(score_first, score_second, PART_DATA_SIZE);
	memcpy(score_second, temp, PART_DATA_SIZE);
}
*/

/*
void Swap_Name(char name_first[], char name_second[])
{
	char temp_name[MAX_NAME_LENGTH];

	strcpy(temp_name, name_first);
	strcpy(name_first, name_second);
	strcpy(name_second, temp_name);
}
*/

/*
void Bubble_Sort(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	for(i=0; i<MAX_STUDENT_COUNT-1; i++)
	{
		for(j=0; j<MAX_STUDENT_COUNT-1-i; j++)
		{
			if(TOTAL[j] > TOTAL[j+1])
			{
				Swap_Name(name[j], name[j+1]);
				Swap_Score(score[j], score[j+1]);
			} 
		}
	}
}
*/

void InputData(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	for(i=0; i<MAX_STUDENT_COUNT; i++)
	{
		LANK[i]=1;

		printf("%s %d 번째 학생 이름 : ", C_YLLW ,i+1); 	scanf("%s", name+i);
		printf("%s 국어 점수 : ", C_BLUE);				 	scanf("%d", score[i] + KOR);
		printf("%s 영어 점수 : ", C_BLUE);				 	scanf("%d", score[i] + ENG);
		printf("%s 수학 점수 : ", C_BLUE);				 	scanf("%d", score[i] + MATH);
		printf("%s 과학 점수 : ", C_BLUE); 			 		scanf("%d", score[i] + SIENCE);
		printf("%s 윤리 점수 : ", C_BLUE); 			 		scanf("%d", score[i] + ETHICS);
		ft_putchar('\n');
	}

	for(i=0; i<MAX_STUDENT_COUNT; i++)
	{		
		TOTAL[i] = score[i][KOR] + score[i][ENG] + score[i][MATH] + score[i][SIENCE] + score[i][ETHICS];
		AVERAGE[i] = TOTAL[i]/PART_COUNT;
	}

	Lank();
}

void Lank()
{
	for(j=0; j<MAX_STUDENT_COUNT; j++)
	{
		for(i=0; i<MAX_STUDENT_COUNT; i++)
		{
			if(TOTAL[i] != TOTAL[j] && TOTAL[i] < TOTAL[j])
			{
				LANK[i]++;
			}		
		}
	}
}

void Display_Result(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	fprintf(tfp,"%s 학번, 성명, 국어, 영어, 수학, 과학, 윤리, 총점, 평균, 석차\n", C_PRPL);

	for(i=0; i<MAX_STUDENT_COUNT; i++){
		fprintf(tfp,"%2d, %6s,  %3d,  %3d,  %3d,  %3d,  %3d,  %3d, %.2f,%3d등\n",
				i+1, name[i], score[i][KOR], score[i][ENG], score[i][MATH], score[i][SIENCE],
				score[i][ETHICS], TOTAL[i], AVERAGE[i], LANK[i]);
	}
}


void Result_scv(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	fprintf(fp,"%s 학번, 성명, 국어, 영어, 수학, 과학, 윤리, 총점, 평균, 석차\n", C_PRPL);

	for(i=0; i<MAX_STUDENT_COUNT; i++){
		fprintf(fp,"%2d, %6s,  %3d,  %3d,  %3d,  %3d,  %3d,  %3d, %.2f,%3d등\n",
				i+1, name[i], score[i][KOR], score[i][ENG], score[i][MATH], score[i][SIENCE],
				score[i][ETHICS], TOTAL[i], AVERAGE[i], LANK[i]);
	}
}

int main(int argc, char *argv[])
{
	char name[MAX_STUDENT_COUNT][MAX_NAME_LENGTH];
	int score[MAX_STUDENT_COUNT][PART_COUNT];

	InputData(name, score);	
	//Bubble_Sort(name, score);

	if((tfp=fopen("notepad.txt","wt")) == NULL)
	{
		errExit("Text File open error\n");
	}
	else
	{
		fprintf(tfp,"Text file_Input complete!!\n");
	}
	Display_Result(name,score);
	

	if((fp=fopen("excell.csv","wt")) == NULL)
	{
		errExit("File open error\n");
	}
	else
	{
		fprintf(fp,"Excell File_Input complete!!\n");
	}

	Result_scv(name,score);
	fclose(tfp);
	fclose(fp);

	char buffer[101];

	printf("%s 저장된 정보를 보여드리겠습니다.\n", C_BLUE);

	printf("%s =====================================================================\n", C_AQUA);
	printf("                          텍스트 파일입니다.                         \n");
	printf("=====================================================================\n");

	if ((tfp = fopen("notepad.txt", "rt")) != NULL)
	{
		memset(buffer, 0, sizeof(buffer));
		while (fread(buffer, 10, 256, tfp) != 0)
		printf("%s\n", buffer);
		fclose(tfp);
	}
	else
	{
		printf("파일 오픈 에러!!!\n");
	}

	printf("%s 성공적으로 파일이 저장되었습니다. 리눅스라면 cat notepad.txt로 확인하세요.\n", C_BLUE);
	ft_putchar('\n');

	printf("%s =====================================================================\n", C_AQUA);
	printf("                           엑셀 파일 입니다.                         \n");
	printf("=====================================================================\n");

	if ((fp = fopen("excell.csv", "rt")) != NULL) 
	{
    	memset(buffer, 0, sizeof(buffer));
    	while (fread(buffer, 10, 256, fp) != 0)
       	printf("%s\n", buffer);
    		fclose(fp);
	}
	else
	{
		printf("파일 오픈 에러!!!\n");
	}
	
	
	printf("%s 성공적으로 파일이 저장되었습니다. 리눅스라면 cat excell.scv로 확인하세요.\n", C_BLUE);

	return (0);	
}

