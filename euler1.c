#include <stdio.h>

int main()
{
	int i, s = 0;
	for (i = 3; i < 1000; i++)
		if (!(i%3) || !(i%5))
			s += i;
	printf("%d\n", s);
}
