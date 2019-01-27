#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }, // < 40
		factorbase[12] = {};

	int i, j, c;

	for (i = 2; i <= 40; i++)
	{
		c = i;
		j = 0;

		while (c != 1)
		{
			if (!(c % primes[j]))
			{
				c /= primes[j];

				if (i > 20)
					factorbase[j]++;
				else
					factorbase[j]--;
			}
			else
				j++;
		}
	}

	long long product = 1;

	for (i = 0; i < 12; i++)
	{
		if (factorbase[i] != 0)
			product *= pow(primes[i], factorbase[i]);
	}

	printf("%lld\n", product);
}