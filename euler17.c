#include <stdio.h>

int namesize(int num)
{
	int under_twenty[] = { 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 },
		over20_prefix[] = { 6, 6, 5, 5, 5, 7, 6, 6 };

	if (num == 1000)
		return 11;
	int size = 0;

	if (num >= 100)
	{
		size = 7;
		size += under_twenty[(num / 100) - 1];
		num %= 100;

		if (num)
			size += 3;
	}

	if (num >= 20)
	{
		size += over20_prefix[(num / 10) - 2];
		num %= 10;
	}

	if (num)
		size += under_twenty[num - 1];

	return size;
}

int main()
{
	int i, total = 0;

	for (i = 1; i <= 1000; i++)
		total += namesize(i);

	printf("%d\n", total);
}