#include <stdio.h>

int main()
{
	long long num;

	int i,j,maxchain = 0,maxnum;

	for (i = 1; i < 1000000; i++)
	{
		num = (long long)i;
		j = 1;

		while (num != 1)
		{
			if (num % 2)
				num = num * 3 + 1;
			else
				num /= 2;
			j++;
		}

		if (j > maxchain)
		{
			maxchain = j;
			maxnum = i;
		}
	}

	printf("%d\n",maxnum);
}