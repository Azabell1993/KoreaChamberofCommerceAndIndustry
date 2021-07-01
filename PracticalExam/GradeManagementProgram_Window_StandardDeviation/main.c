#include "program.h"
#include "math.h"




void InputData(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	for(i=0; i<MAX_STUDENT_COUNT; i++)
	{
		//���� ���ϱ� �ʱ�ȭ
		LANK[i]=1;

		//���°�л�, �������� �Է¹޴� ����
		printf("%d ��° �л� �̸� : ", i+1); 	scanf("%s", name+i);
		printf("���� ���� : ");				 	scanf("%d", score[i] + KOR);
		printf("���� ���� : ");				 	scanf("%d", score[i] + ENG);
		printf("���� ���� : ");				 	scanf("%d", score[i] + MATH);
		printf("���� ���� : "); 			 		scanf("%d", score[i] + SIENCE);
		printf("���� ���� : "); 			 		scanf("%d", score[i] + ETHICS);
		printf("\n");
		//ft_putchar('\n');
	}

	//�и��ؼ� �����ϱ� ���� ���հ� ����� ���ϴ� �ݺ��� ����
	for(i=0; i<MAX_STUDENT_COUNT; i++)
	{		
		TOTAL[i] = score[i][KOR] + score[i][ENG] + score[i][MATH] + score[i][SIENCE] + score[i][ETHICS];
		SSUM += TOTAL[i];
		AVE = SSUM/MAX_STUDENT_COUNT;
		AVERAGE[i] = TOTAL[i]/PART_COUNT;
	}~

	//�������ϱ� �����Լ�
	Lank();
}




//���� ���ϱ�
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

//�ؽ�Ʈ ���� �ҷ����� �Լ�
void Display_Result(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	fprintf(tfp,"%�й�, ����, ����, ����, ����, ����, ����, ����, ���, ����\n");

	for(i=0; i<MAX_STUDENT_COUNT; i++){
		fprintf(tfp,"%2d, %6s,  %3d,  %3d,  %3d,  %3d,  %3d,  %3d, %.2f,%3d��\n",
				i+1, name[i], score[i][KOR], score[i][ENG], score[i][MATH], score[i][SIENCE],
				score[i][ETHICS], TOTAL[i], AVERAGE[i], LANK[i]);
	}
	
	Loop_Result(score);
	
	fprintf(tfp,"\n");
	
	fprintf(tfp, "���� : %d\n", SSUM);
	fprintf(tfp, "�� ��� : %2f\n", AVE);
	
	void Result_SSUM();
	
	fprintf(tfp,"���� �л� , %.3d,  ���� ǥ�� ���� , %.3f\n", variance_SSUM, std_deviation_SSUM);
	
}

//�������� �ҷ����� �Լ�
void Result_scv(char name[][MAX_NAME_LENGTH], int score[][PART_COUNT])
{
	fprintf(fp,"�й�, ����, ����, ����, ����, ����, ����, ����, ���, ����\n");

	for(i=0; i<MAX_STUDENT_COUNT; i++){
		fprintf(fp,"%2d, %6s,  %3d,  %3d,  %3d,  %3d,  %3d,  %3d, %.2f,%3d��\n",
				i+1, name[i], score[i][KOR], score[i][ENG], score[i][MATH], score[i][SIENCE],
				score[i][ETHICS], TOTAL[i], AVERAGE[i], LANK[i]);
	}
	
	Loop_Result_2(score);
	
	fprintf(fp,"\n");
		
	fprintf(fp, "���� : %d\n", SSUM);
	fprintf(fp, "�� ��� : %2f\n", AVE);
	
	void Result_SSUM_2();
	
	fprintf(fp,"���� �л� , %.3d,  ���� ǥ�� ���� , %.3f\n", variance_SSUM, std_deviation_SSUM);
	
}

int main(int argc, char *argv[])
{
	char name[MAX_STUDENT_COUNT][MAX_NAME_LENGTH];
	int score[MAX_STUDENT_COUNT][PART_COUNT];

	InputData(name, score);	
	//Bubble_Sort(name, score);

	//�ؽ�Ʈ ���Ͽ� ���� ���ؼ� �����ش�.
	if((tfp=fopen("notepad.txt","wt")) == NULL)
	{
		printf("Text File open error\n");
	}
	else
	{
		fprintf(tfp,"Text file_Input complete!!\n");
	}
	Display_Result(name,score);
	

	//���� ���Ͽ� ���� ���ؼ� �����ش�.
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
