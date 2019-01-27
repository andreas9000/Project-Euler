#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char * sum, char * add)
{
	int trailing, carry = 0, i, diff = strlen(sum) - strlen(add);

	for (i = strlen(sum) - 1; i >= 0; i--)
	{
		trailing = *(sum + i) - '0' + carry; 
		if (i >= diff)
			trailing += *(add + i - diff) - '0';
		carry = trailing / 10;
		*(sum + i) = trailing % 10 + '0';
	}
}

int main()
{
	char * a = calloc(1001, 1),
		* b = calloc(1001, 1);

	int i, count = 2;
	for (i = 0; i < 999; i++)
	{
		*(a + i) = '0';
		*(b + i) = '0';
	}
	*(a + 999) = '1';
	*(b + 999) = '1';

	while (!(*a - '0') && !(*b - '0'))
	{
		if (count++ % 2)
			add(a, b);
		else
			add(b, a);
	}
	printf("%d\n", count);
}