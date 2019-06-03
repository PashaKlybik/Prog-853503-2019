#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int N, a[100000], min, max, i, K, sum = 0;
	printf("%s", "Enter N:\t");
	scanf_s("%d", &N);
	printf("%s", "Enter array:\n");
	for (i = 0; i < N; i++)
		scanf_s("%d", &a[i]);
	printf("%s", "Enter K:\t");
	scanf_s("%d", &K);
	max = min = a[0];
	for (i = 0; i < N; i++)
	{
		if (a[i] < min)			
			min = a[i];
		if (a[i] > max)			
			max = a[i];
		sum += a[i];			
	}
	int sum0;
	if (K > 0)
	{
		sum0 = sum;
		sum = N * min - sum;	
		min -= max;				
		max = min;				
		if (K % 2 == 0)
			sum = N * (min + max) - sum0;	
	}
	printf_s("%s%d", "Sum = ", sum);
	getch();
}