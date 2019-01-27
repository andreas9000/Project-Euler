#include <stdio.h>

int main()
{
	int max = 0, a, b;
	char str[7];

	for (a = 100; a <= 999; a++)
		for (b = a; b <= 999; b++)
		{
			sprintf(str, "%d", a * b);
			if (str[0] == str[5] && str[1] == str[4] && str[2] == str[3])
				if (a * b > max)
					max = a * b;
		}
	printf("%d\n", max);
}
