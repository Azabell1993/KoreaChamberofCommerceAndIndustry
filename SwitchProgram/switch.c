#include <stdio.h>

int sum(int x, int y)
{
	while (y != 0) {
		int temp = x & y;
		x = x ^ y;
		y = temp << 1;
	}
	return x;
}

int sub(int x, int y)
{
	while (y != 0) {
		int temp = ~x & y;
		x = x ^ y;
		y = temp << 1;
	}
	return x;
}

int multiplication(int x, int y)
{
	int temp = x * y;
	return temp;
}

int Division(int x, int y)
{
	if (x != 0 && y != 0)
	{
		if (x % y) {
			printf("%.2f", x / (float)y);
		} else if (y % x) {
			printf("%.2f", (float)x / y);
		}
		else {
			printf("%d", x/y);
		} 
	} else {
		printf("error!");
	}
}

int main(void)
{
	int a, b;
	char ch;
	
	scanf("%d %c %d", &a, &ch, &b);
	
	switch (ch)
	{
	case '+': { printf("%d %c %d = ", a, ch, b); printf("%d", sum(a, b));				break; }
	case '-': { printf("%d %c %d = ", a, ch, b); printf("%d", sub(a, b));				break; }
	case '*': { printf("%d %c %d = ", a, ch, b); printf("%d", multiplication(a, b));	break; }
	case '/': { printf("%d %c %d = ", a, ch, b); Division(a,b);							break; }

	default: ch = 0; break;
	}

	return (0);
}

