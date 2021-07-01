#include "program.h"
/*
#include <fcntl.h>

#define MAX_READ 1001
char string[MAX_READ];
char string2[MAX_READ];

ssize_t read(int fd, void *buffer, size_t count);
*/
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

	ft_putchar('\n');
	printf("당신이 풀 문제들입니다.\n");
	ft_putchar('\n');

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

	printf("-------------------------------------------------\n");
	printf(" result.txt파일로 결과가 저장되었습니다.        \n");

	i = 1;
	while (i <= count_index)
		{		
			if (key == '/') 
			{
				fprintf(fp, "%s [%2d번] 답 = %5.2f  <<<<< 정답 여부 : ", C_NRML, i, Que_result_split[i]);
				if(Que_result_split[i] == float_answer[i])
				{
					fprintf(fp, "%s  [ OK ] \n", C_YLLW);
					correct_count++;
				}
				else
				{
					fprintf(fp, "%s  [ NG ] \n", C_RED);
					ng_count++;

				}
				ft_putchar('\n');
			}
			else
			{
				fprintf(fp, "%s [%2d번] 답 = %4d  <<<<< 정답 여부 : ", C_NRML, i, Que_result[i]);
				if(Que_result[i] == int_answer[i])
				{
					fprintf(fp, "%s  [ OK ] \n", C_YLLW);
					correct_count++;
				}
				else
				{
					fprintf(fp, "%s  [ NG ] \n", C_RED);
					ng_count++;
				}
				ft_putchar('\n');
			}
			i++;
		}

	printf("%s ================================================ \n", C_YLLW);
	printf("%s ================================================ \n", C_RED);
	printf("%s   고 생 하 셨 습 니 다.                          \n", C_YLLW);
	printf("%s ================================================ \n", C_RED);
}

void ft_putchar(char enter)
{
	write(1, &enter, 1);
}

void ft_sumbit()
{
	printf("차례대로 정답을 적으시오. 자동으로 채점을 도와줄 겁니다. (소숫점 계산은 소수 둘째자리깢. 0.15) \n");
	ft_putchar('\n');

	count = 1;
	do
	{
		if(key == '/')
		{
			printf("문제 번호 [%3d] : ", count);
			scanf("%f", &float_answer[count]);
			ft_putchar('\n');
		}
		else if(key == '+' || '-' || '*')
		{
			printf("문제 번호 [%3d] : ", count);
			scanf("%d", &int_answer[count]);
			ft_putchar('\n');
		}
		else
		{
			printf("input data error!");
		}
		count++;
	} while ( count <=  count_index);
}


void Print()
{
	printf("#########################################\n");
	printf("## 기탄수학  문제은행  방가워요        ##\n");
	printf("##       /--8--8-|                     ##\n");
	printf("##      ||  0 .0 |__                   ##\n");
	printf("## (    ((    o   __| 0 0 // 아무키나  ##\n");
	printf("##      || |_|   |           누르세요. ##\n");
	printf("##      ||       |                     ##\n");
	printf("##      ||-------/       0 o  o0 0     ##\n");
	printf("##        |_| |_|        |/   /| |     ##\n");
	printf("#########################################\n");
	ft_putchar('\n');
} 

void Arch_logo()
{

	ft_putchar('\n');
	ft_putchar('\n');
	printf("%s M8MMMMMMMMMMMMMMM8MMMMMMMMM8MMM8M8M8MMMMMMMMMMMMMMMMMMMMM8MMM8MMMMMMMMMMMMM8M8MMM8MMMMM8MMMMM8MMMMMM\n", C_NRML);
	printf("%s 88888M8M8M8MZMZM8M888M8M8M8M8M8M8M8M8M8M888M888M888M8M8M88888M8M8M8M888M8M8M8M8M8M8M8M8M8M8M8M8M8M88\n", C_RED);
	printf("%s M8M8MMM8MMMMMMMMMMMMMMMMMMM8MMMMMMM8M8M8MMMMMMMMMMMMMMM8M8MMMMMMMMMMMMM8M8M8MMM8M8M8MMMMM8MMMMMMM8M8\n", C_GREN);
	printf("%s MM8MMM8MMMMMMBBBBBBBBBBBMMMMMMMMMMMMMMMMMMMMMM8M8MMMMM8M8MMM8M8MMMMMMMMMMMMMMMMM8MMMMMMMMMMMMM8MMM8M\n", C_YLLW);
	printf("%s M8MMM8M8MMBBBB77222727XBBBBMM8M8MMMMM8MMM8M8MMM8M8M8MMMMM8MMMMMMMMM8M8M8MMM8MMMMM8MMBM8BMMM8MMM8MMM8\n", C_BLUE);
	printf("%s MMMM8MMMBBS727         X27BBMMMM8M8M8M8M8MMM8M8M8M8M8MMM8M8M8M8M8MMM8M8M8M8M8M8M8MMMBi BBM8M8M8M8M8M\n", C_PRPL);
	printf("%s M8M8MMMB02      . . .     r2BMM8MMMMM8M8M8MMM8MMMMMMMMMMMMM8M8MMM8M8MMM8M8M8M8MMMMMBX.iiBMMMM8M8M8M8\n", C_AQUA);
	printf("%s 8MMMMMBBr    .........      8BMMMBBBMMMM8M8MMMMMMMMBMBMMMM8MMM8MMMMBBBMMMMMMMM8M8MBB.72.2BMM8M8MMMM8\n", C_NRML);
	printf("%s 8M8MMMSi ..... ..      .i::MMMBBBBBBBMMM8MMM8MMBBBBBBBMMMM8M8M8bMMBBBBBBBMM8M8MMMBB.:227.0BMMMM8M8MZ\n", C_RED);
	printf("%s 88MMMB2  ....      :ii:.0BBBMMBBi   :MBM8M8M8MMBBr   .0BMM8MMM8MBB7    SBBMMMM8MMBr.:7727.8BMMMM8MMM\n", C_GREN);
	printf("%s M8M8MBX  ... .277rrBBBBBBMMMMBB       MBM8M8M8BB       SBMM8MMMMB:      7BM8M8MMB7:227772r.BBMMMM8MZ\n", C_YLLW);
	printf("%s M88MMBS  ... iBBBBMBBBBBBMMMMBZ       2BMM8M8MMB       rBM8M8M8MB       .BMM8MMB7.7277r772i:BBMM8MM8\n", C_BLUE);
	printf("%s M8M8MB2  ....      XM00XBBBBMMB7     :BMM8M8MMMBS     .BBMM8M8MMB0      BBM8MMB2.727i72:772iiBBMM8M8\n", C_PRPL);
	printf("%s 88MMMBX.  .... .        rBXXMMMBBX7SMBBMMM8M8M8MBBX22MBBMM8M8M8MMBB022ZBBMMMMBS.777rrBBX:272.rBBMM88\n", C_AQUA);
	printf("%s M8M8MMBB7  ........         MBMMBBBBBMM8M8M8M8M8MBBBBBBMM8M8M8M8MMBBBBBMM8MMBX.7277.7BBM r777 iBB8MZ\n", C_NRML);
	printf("%s 888M8MMB7      .......      MB8M8MMM8M8M8M8M8M8M8MMMMM8M8M8M8M8M8MMM8M8M8MMB0.ii:r72XBMM27riir.7BM88\n", C_RED);
	printf("%s MZM8M8MMBBi .          .. MBBMM8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M888M888M8B2 :7SMBBBB8MMBBBM07r rBM8\n", C_GREN);
	printf("%s 8M8M888MMBBBBM   . .  iBBBBBMM8M888M8M888M8M8M8M888M8M888M8M8M8M8M8M8M8M8MMr2BBBBMMM8M8MMMMBBBB0i0MM\n", C_RED);
	printf("%s MZM8M8M8MMBMBBBBBBBBBBBBBMMMM8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M8M8MMMBBMM8M8M8M8M8M8M8MMMBBMMZ\n", C_RED);
	printf("%s M08808Z8088MZMMBMBMBMMMMZMZ8Z8Z8Z8ZMZ8Z8Z808Z8Z8Z80MZ8Z8Z8088888Z808ZM08Z8Z8ZM0MZ8Z8ZM08Z8Z8Z8ZMZ8Z8\n", C_NRML);
	ft_putchar('\n');
	ft_putchar('\n');
}

int main(int argc, char *argv[])
{
	Arch_logo();
	Print();
	
	key = linux_console();

	ft_Choose();
	ft_make_qes();

	page = make_page;
	count_index = page * LIMIT_PAGE;
	srand(time(NULL));

	ft_Result();

	ft_sumbit();

	fp = fopen("result.txt", "w");


	if(fp == NULL)
	{
		errExit("File OpEn Err..oR..\n");
	}
	fprintf(fp, "\n");
	fprintf(fp, "\n");
	fprintf(fp, "\n");

	fprintf(fp, "InPu..T ComPlE..tE!!\n");

	printf("%s   ,,                     :::ii ,   , , , , , ,  ,, , , , , , , , ,,,,,,:,  , , , , , , , ,  ,  , ,\n", C_BLUE);
	printf("                           ,  ,                                         ,,\n");
	printf("    :           ,,,,,,,       :,  , , ,         , ,,                     ,            ,       , ,,,\n");
	printf("    ,,     ,,,,,,,      ,     ,:                   ,                     ,                   ,:,,,,\n");
	printf("    ,: ,,,,           sBs     ,:        ,r2X9hs    ,BBBBMB  BG  sBBBBB :B,    sBBBBBs   ,::   ,,\n");
	printf("  ,, :              rGM,       ,,     rGMGsr:ii     , BB  S2BG  MB     :Bhs  rB2   hBs  BBBBs  :\n");
	printf("     ,,            shh,         ,   :MMs,            2BMM,, BG  MBss2X,,B95,  s99hX9s      BB  ,, ,\n");
	printf("     ,,            9sr          :, iBs             ,BB  sB: Ms  ,:B ,:  B  ,h9r2GBM92G9  sB2   ,,\n");
	printf("      :           ,9h   ,:rrsrsrrrrsr,irrri,,         :Bh2hGB,    BBBBBBB  ,:sB:  ,,,:i  M5     ,\n");
	printf("      ,,       ,   9M,rsrr:,           ,,,:irsrr,     BB   ,BB ,  B     B: , :Bs,::::    MB  ,  ,,\n");
	printf(",      ,,,    ,   ,22:,   ,   ,,,,,,, ,,,     ,issi   ,XBBBBs     MG9999B,   ,99GGGGM:   ,i      ,\n");
	printf("     r,    :  :sr,   ,,,, ,i ,,, rs:,,,  ,     ,s2i                       ,                    ,,\n");
	printf("      ,,  ,,,,i2r   , ,,,,,,2i ,,,, ::,, :i,s   ,   rs,                     ,       ,:rshi        ,\n");
	printf("     ,,,i,,, ss, ,,,,    ,,,, ,,,,,, ,,, BS B9 ,,,,, ,2s                     ,   ,::::i2          ,\n");
	printf("    ,,,,i,, si  ,,,,  ri, , ,,,,,,,,,,,, 2BSB9, ,,,,,  s5                     ,rr::isrr           ,\n");
	printf("  ,:,,,,:: h2  ,,,,, M: Br ,,,,,,,,,,,,,  r, ,:,,,,,,,, i9                  isrrirr:\n");
	printf("  :,,,,,,,sM  ,,,,,, 9BsBM  ,,,,,,         ,,,,,,,,,,,,,,:G              :ssrisr:\n");
	printf(",,,,,,,, iBi ,,,,,,,  GMsr:,,,,,  ,rrissi,   , ,,,,,,,,,,,iG           rsr:rsr,               ,,,,,\n");
	printf(", ,,,,:, 2h  ,,,,,,,, i   :,,,, ,2M   s2s22, ,,,,,,,,,,,,,,rh       ,ss::ss:   ,          ,,,,:,\n");
	printf(",,:::::,,9s  ,,,,,,,,,,,,,,,,, i9rrriiri:irG ,,,,,,,,,,,,,,,ss    :sr:iss,     ,,    ,,,,,,,\n");
	printf(":,:,,,, shr ,,,,,,,,,,,,, ,,, ,9i:iissssss22 ,,,,,,,,,,,,,,,,X  isr:rsr         : ,,,,,\n");
	printf(", ,,,,, 22i ,,,,,,,,,,,,,,,,, ,Gsrs5s:,iir:  ,,,,,,,,,,,,,,,,:Xsr:rs:      ,,,,,,,\n");
	printf(": ,,,,, hs: ,,,,,,,,,,,,,,,,,, ,srr,        ,,,,,,,,,,,,,,,,, 2sis:   ,,,,,,,    ,\n");
	printf(",,,,,,,,hs: ,,,,,,,,,,,,,,,,,,,         ,i ,,,,,,,,,,,,,,,,,,,,M,  ,,,,,         ,\n");
	printf(": ,,,,,,9r: ,,,,,,,,,,,,,,,,,,,,,,,,,,ir5r ,,,,,,,,,,,,,,,,,,,,s:                ,,\n");
	printf(",,,,,,,,Ss: ,,,,,,,,,,,,,,,,,,,,,,,,,rsr,, ,,,,,,,,,,,,,,,,, ,,:2                 ,\n");
	printf(", ,,,,,,hrr ,,,,,,,,,,,,,,,,,,,,,,,,:,,,, ,,,,,,,,,,,,,,,,,,,,:,h,                ,,\n");
	printf(",,,,,,,,hrr ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,r2                ,,\n");
	printf(", ,,,,, 9rs ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,h                 ,\n");
	printf(",,,:,:, 2ss, ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,:,2r  ,  ,,         :,\n");
	printf(": , ,   rsr,                                                   ,,,2\n");

	                 
	printf("%s 답안지는 숫자 '1' 키를 누르시면 됩니다.\n", C_YLLW);
	printf("  종료하려면 아무키나 입력해주세요.\n");
	printf("===================================\n");

	
	int num;
	scanf("%d", &num);

	if ( num == 1) 
	{
		ft_Display_output_ques_result();
		ft_putchar('\n');
		fprintf(fp, "\n\n\n");
		fprintf(fp, "%s 정답의 개수는 %d개 입니다.\n",C_YLLW, correct_count);
		fprintf(fp, "%s 오답의 개수는 %d개 입니다.\n",C_RED,  ng_count);
		fprintf(fp, "-----------------------------------------------------------------------------\n\n\n");
		ft_putchar('\n');
	}
	else
	{
		printf("정답,채점 없이 종료합니다!!  thank you!\n");
	}
	

	fclose(fp);
	return (0);
}


