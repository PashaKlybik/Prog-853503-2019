#include "pch.h"
#include <stdlib.h>
#include <stdio.h>

bool checkComposition(long long int a)
{
	bool f = false, f1 = false;
	long long i = 0, b = a;
	long long int *arr;
	while (b)
	{
		b /= 10;
		i++;
	}
	arr = (long long int*)malloc(i * sizeof(long long int));
	for (long long j = 0; j < i; j++)
	{
		arr[j] = a % 10;
		a /= 10;
	}
	for (int j = 0; j < i; j++)
	{
		if (arr[j] == 4) f = true;
		if (arr[j] == 7) f1 = true;
	}
	if (f == true && f1 == true) { return true; }
	else { return false; }
}

int main()
{
	long long b,n=0;
	scanf_s("%lld", &b);
	for (long long i = 1; i < b; i++)
	{
		if (b % i == 0)
		{
			if (checkComposition(i) == true)
			{
				printf("%lld\n", i);
				n++;
			}
		}
	}
	printf("number of almost happy divisors  %lld\n", n);
}
