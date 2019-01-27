#include <stdio.h>

int count = 0, val[] = { 1, 2, 5, 10, 20, 50, 100, 200 };

void withdraw(int amount, int highest)
{
	if (!amount)
	{
		count++;
		return;
	}

	int i;
	for (i = 0; i <= highest; i++)
	{
		if (amount - val[i] >= 0)
			withdraw(amount - val[i], i);
	}
}


int main()
{
	withdraw(200, 7);
	printf("%d\n", count);
}