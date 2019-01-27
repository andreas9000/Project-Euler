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
	char * num = calloc(303, 1);
	*(num + 301) = '1';

	int i, sum = 0;

	for (i = 0; i <= 300; i++)
		*(num + i) = '0';
	for (i = 0; i < 1000; i++)
		add(num, num);
	for (i = 0; i < 302; i++)
		sum += *(num + i) - '0';

	printf("%s\n", num);
	printf("%d\n", sum);
}