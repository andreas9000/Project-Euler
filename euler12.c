#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int factorial(int n)
{
	if (n == 1)
		return 1; 
	else
		return n * factorial(n - 1);
}

int main()
{
	int sum = 0, sumc, i = 1, j, c, permutations;

	// Assumption: first occurance will have small composites
	int some_primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };

	while (sum < INT_MAX)
	{
		sum += i++;
		sumc = sum;
		permutations = 1;
		c = 0;

		for (j = 0; j < 15; j++)
		{
			if (!(sumc % some_primes[j]))
			{
				c++;
				sumc /= some_primes[j];
				j--;
			}
			else if (c)
			{
				permutations *= (c + 1);
				c = 0;
			}
			if (permutations + 1 > 500)
			{
				printf("%d\n", sum);
				exit(0);
			}
		}
	}
}