#include "linux_gcc.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	ft_putchar('A');
	ft_putchar('\n');
	ft_putchar('h');
	ft_putchar('e');
	ft_putchar('l');
	ft_putchar('l');
	ft_putchar('o');
	ft_putchar('\n');

	write(1, "world!!", 7);

	int a;
	int b;

	a = 10;
	b = 20;
	write(1, "\n", 1);
	printf("min : %d\n", min(a, b));
	printf("max : %d\n", max(a, b));

	return (0);
}

