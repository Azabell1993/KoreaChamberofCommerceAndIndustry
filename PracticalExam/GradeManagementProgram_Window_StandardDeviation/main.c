#include "program.h"
#include "math.h"




void InputData(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	for(i=0; i<MAX_STUDENT_COUNT; i++)
	{
		//석차 구하기 초기화
		LANK[i]=1;

		//몇번째학생, 점수들을 입력받는 구간
		printf("%d 번째 학생 이름 : ", i+1); 	scanf("%s", name+i);
		printf("국어 점수 : ");				 	scanf("%d", score[i] + KOR);
		printf("영어 점수 : ");				 	scanf("%d", score[i] + ENG);
		printf("수학 점수 : ");				 	scanf("%d", score[i] + MATH);
		printf("과학 점수 : "); 			 		scanf("%d", score[i] + SIENCE);
		printf("윤리 점수 : "); 			 		scanf("%d", score[i] + ETHICS);
		printf("\n");
		//ft_putchar('\n');
	}

	//분리해서 수정하기 쉽게 총합과 평균을 구하는 반복문 구현
	for(i=0; i<MAX_STUDENT_COUNT; i++)
	{		
		TOTAL[i] = score[i][KOR] + score[i][ENG] + score[i][MATH] + score[i][SIENCE] + score[i][ETHICS];
		SSUM += TOTAL[i];
		AVE = SSUM/MAX_STUDENT_COUNT;
		AVERAGE[i] = TOTAL[i]/PART_COUNT;
	}~

	//석차구하기 내장함수
	Lank();
}




//석차 구하기
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

//텍스트 파일 불러오기 함수
void Display_Result(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	fprintf(tfp,"%학번, 성명, 국어, 영어, 수학, 과학, 윤리, 총점, 평균, 석차\n");

	for(i=0; i<MAX_STUDENT_COUNT; i++){
		fprintf(tfp,"%2d, %6s,  %3d,  %3d,  %3d,  %3d,  %3d,  %3d, %.2f,%3d등\n",
				i+1, name[i], score[i][KOR], score[i][ENG], score[i][MATH], score[i][SIENCE],
				score[i][ETHICS], TOTAL[i], AVERAGE[i], LANK[i]);
	}
	
	Loop_Result(score);
	
	fprintf(tfp,"\n");
	
	fprintf(tfp, "총점 : %d\n", SSUM);
	fprintf(tfp, "총 평균 : %2f\n", AVE);
	
	
}

//엑셀파일 불러오기 함수
void Result_scv(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	fprintf(fp,"학번, 성명, 국어, 영어, 수학, 과학, 윤리, 총점, 평균, 석차\n");

	for(i=0; i<MAX_STUDENT_COUNT; i++){
		fprintf(fp,"%2d, %6s,  %3d,  %3d,  %3d,  %3d,  %3d,  %3d, %.2f,%3d등\n",
				i+1, name[i], score[i][KOR], score[i][ENG], score[i][MATH], score[i][SIENCE],
				score[i][ETHICS], TOTAL[i], AVERAGE[i], LANK[i]);
	}
	
	Loop_Result_2(score);
	
	fprintf(fp,"\n");
		
	fprintf(fp, "총점 : %d\n", SSUM);
	fprintf(fp, "총 평균 : %2f\n", AVE);
	
	
}

int main(int argc, char *argv[])
{
	char name[MAX_STUDENT_COUNT][MAX_NAME_LENGTH];
	int score[MAX_STUDENT_COUNT][PART_COUNT];

	InputData(name, score);	
	//Bubble_Sort(name, score);

	//텍스트 파일에 쓰기 위해서 열어준다.
	if((tfp=fopen("notepad.txt","wt")) == NULL)
	{
		printf("Text File open error\n");
	}
	else
	{
		fprintf(tfp,"Text file_Input complete!!\n");
	}
	Display_Result(name,score);
	

	//엑셀 파일에 쓰기 위해서 열어준다.
	if((fp=fopen("excell.csv","wt")) == NULL)
	{
		printf("File open error\n");
	}
	else
	{
		fprintf(fp,"Excell File_Input complete!!\n");
	}

	Result_scv(name,score);
	

	return (0);	
}
