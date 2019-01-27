#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long p = 600851475143,
		it, high = 0;


	for (it = 3; it <= p; it += 2)
		if (p % it == 0)
		{
			p /= it;
			high = it; 
		}

	printf("%llu\n", high);
}
