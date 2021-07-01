#include "linux_gpp.h"

void	print(T a, T b)
{
	cout << a << ", " << b << endl;
}

int		main(void)
{
	print<int> (10, 20);
	print<const char*> ("ABC", "abcd");
	return (0);
}

