#include <stdio.h>
#include <stdlib.h>

void add(char * sum, char * add)
{
	int trailing, carry = 0, i;

	for (i = 51; i >= 0; i--)
	{
		trailing = *(sum + i) - '0' + carry; 
		if (i >= 2)
			trailing += *(add + i - 2) - '0';
		carry = trailing / 10;
		*(sum + i) = trailing % 10 + '0';
	}
}

int main()
{
	char * sum = calloc(53, 1), *line = calloc(51, 1);

	int i;
	for (i = 0; i < 52; i++)
		*(sum + i) = '0';

	FILE *fp = fopen("nums.txt", "r");

	if (fp != NULL)
	{
		for (i = 0; i < 100; i++)
		{
			if (fgets(line, 51, fp) != NULL)
			{
				add(sum, line);
				fgets(line, 51, fp);
			}
		}
		fclose(fp);
	}
	*(sum + 10) = '\0';
	printf("%s\n", sum);
	free(sum);
	free(line);
}