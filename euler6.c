#include <stdio.h>

int main()
{
	int s = 0, i;

	for (i = 1; i <= 100; i++)
		s += (i * i);

	printf("%d\n", (5050 * 5050) - s);
}
