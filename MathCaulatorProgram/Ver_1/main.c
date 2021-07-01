#include "program.h"

void ft_Choose()
{
	do {
		printf("원하는 연산을 고르시오. +,_,*,/  :   ");
		scanf("%c", &key);
	} while (!((key == '+' || '-' || '*' || '/')));

	do {
		printf("원하는 연산의 자릿수는? (1~3) :   ");
		scanf("%d", &make_q_number);
	} while (! (make_q_number));

	clip = make_q_number;
}

void ft_make_qes()
{
	if (clip == 1)
	{
		make_space = 10;
	}
	else if (clip == 2)
	{
		make_space = 100;
	}
	else if (clip == 3)
	{
		make_space = 1000;
	}
	else make_space = 10;

	do
	{
		printf("몇 페이지를 할 것 입니까? (1 ~ 5) :   ");
		scanf("%d", &make_page);
	}while (!(make_page < 6));
}


void ft_Result()
{
	i = 1;
	while (i <= count_index)
	{
		Que_first[i] = rand() % make_space;
		Que_second[i] = rand() % make_space;

		switch(key)
		{
			case '+' : ft_Sum();			break;
			case '-' : ft_Sub();		break;
			case '*' : ft_Multiplication();		break;
			case '/' : ft_split(); break;
			default : printf("예외 연산자\n");  break;
		}
		i++;
	}

	i = 1;
	while (i <= count_index)
	{
		printf("%6d) %12d) %12d) %12d) \n", i, i+1, i+2, i+3);
		printf("%13d  %13d  %13d  %13d\n", Que_first[i], Que_first[i+1], Que_first[i+2], Que_first[i+3]);
		printf("%2c%11d  %2c%11d  %2c%11d  %2c%11d\n", key, Que_second[i], key, Que_second[i+1], key, Que_second[i+2], key, Que_second[i+3]);
		printf("  ------------ ");
		printf("  ------------ ");
		printf("  ------------ ");
		printf("  ------------ ");

		if ( count_index % 4 == 0) printf("\n\n\n\n\n");

		i += 4;
	}
}

void ft_Display_output_ques_result()
{

	printf("================================================= \n");
	printf("====================Result======================= \n");

	i = 1;
	while (i <= count_index)
		{		
			if (key == '/') 
			{
				printf("%2d = %5.2f\n", i, Que_result_split[i]);
			}
			else
			{
				printf("%2d = %8d\n", i, Que_result[i]);
			}
			i++;
		}	
}

void Print()
{
	printf("#########################################\n");
	printf("## 기탄수학  문제은행  방가워요        ##\n");
	printf("##       /--8--8-|                     ##\n");
	printf("##      ||  0 .0 |__                   ##\n");
	printf("## (    ((    o   __| 0 0 // 아무키나  ##\n");
	printf("#       || |_|   |           누르세요. ##\n");
	printf("%#)     ||       |                     ##\n");
	printf("##)     ||-------/       0 o  o0 0     ##\n");
	printf("##        |_| |_|        |/   /| |     ##\n");
	printf("#########################################\n");
} 

int main(int argc, char *argv[])
{
	Print();
	
	key = linux_console();

	ft_Choose();
	ft_make_qes();

	page = make_page;
	count_index = page * LIMIT_PAGE;
	srand(time(NULL));

	ft_Result();

	printf("답안지는 숫자 '1' 키를 누르시면 됩니다.\n");
	printf("===================================\n");

	
	int num;

	scanf("%d", &num);

	
	if ( num == 1) 
	{
		ft_Display_output_ques_result();
	}
	else 
	{
		printf("thank you!\n");
	}

	return (0);
}
