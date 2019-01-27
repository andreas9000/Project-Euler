#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,c;

	for (a = 1; a <= 997; a++)
	{
		for (b = a + 1; b <= 499 && (a + b) < 1000; b++)
		{
			c = 1000 - a - b;

			if (c > b)
			{
				if (a * a + b * b == c * c)
				{
					printf("%d\n", a * b * c);
					exit(0);
				}
			}
		}
	}
}