#include "pch.h"
#include <iostream>

int sum(int k, ...)
{
	int *p = &k;
	p++;

	int sum = 0;
	int temp = 1;

	while (k - 1)
	{
		if (temp % 2 == 1)
		{
			sum += *p * *(p + 1);
			temp = 0;
		}
		else
		{
			sum -= *p * *(p + 1);
			temp = 1;
		}
		p++;
		k--;
	}

	return sum;
}

int main()
{
	printf("Sum of 1, 2, 5, 2, 3 = %d\n", sum(5, 1, 2, 5, 2, 3));
	printf("Sum of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 = %d\n", sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
	printf("Sum of 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 = %d\n", sum(12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1));
}