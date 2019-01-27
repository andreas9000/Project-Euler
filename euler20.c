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

void multiply(char * num, int a)
{
	char * _num = malloc(201);
	memcpy(_num, num, 201);

	int i;
	for (i = 1; i < a; i++)
		add(num, _num);

	free(_num);
}

int main()
{
	char * num = calloc(201, 1);
	int i, j = 0;

	for (i = 0; i < 199; i++)
		*(num + i) = '0';
	*(num + 199) = '1';

	for (i = 2; i <= 100; i++)
		multiply(num, i);

	for (i = 0; i < 200; i++)
		j += *(num + i) - '0';

	printf("%d\n", j);
}