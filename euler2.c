#include <stdio.h>

int main()
{
	int a = 1, b = 2, s = 2, c = 1;

	while (s <= 4000000)
	{
		b += a;
		a = b - a;

		if (c++ % 3 == 0)
			s += b;
	}

	printf("%d\n", s);
}
