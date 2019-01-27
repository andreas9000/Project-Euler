#include <stdio.h>
#include <stdlib.h>

int main()
{
	char * map = calloc(2000000, 1);
	long long found_sum = 0;

	int i,j;
	for (i = 2; i < 2000000; i++)
	{
		if (!*(map + i))
		{
			found_sum += (long long)i;

			for (j = i; j < 2000000; j += i)
				*(map + j) = 1;
		}
	}

	printf("%lld\n", found_sum);
}