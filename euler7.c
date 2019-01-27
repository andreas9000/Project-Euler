#include <stdio.h>
#include <stdlib.h>

int main()
{
	char * map = calloc(200000, 1); // should be quite sufficient according to PNT
	int i, j, np = 1, c = 0;

		for (i = np+1; i < 200000; i++)
			if (*(map + i) == 0)
			{
				for (j = i; j < 200000; j += i)
					*(map+j) = 1;

				if (++c == 10001)
				{
					printf("%d\n", i);
					exit(0);
				}
				np = i;
			}
}
