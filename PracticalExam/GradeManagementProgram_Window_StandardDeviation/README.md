# standard_deviation

Algorithm to find variance and standard deviation of each 

```c

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
```  
