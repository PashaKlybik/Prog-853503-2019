
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

void mainFunction(int *arr,int amount) 
{
	int min, repeat;
	scanf_s("\n%d", &repeat);
	while (repeat)
	{
	min = arr[0];
		for (int i = 0; i < amount; i++)
		{
			if (arr[i] < min) min = arr[i];
		}
		for (int i = 0; i < amount; i++)
		{
			arr[i] = min - arr[i];
		}
		for (int i = 0; i < amount; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		repeat--;
	}
}

int main()
{
	int amount, * arr, min, repeat=0,sum=0;
	scanf_s("%d", &amount);
	arr = (int*)malloc(amount * sizeof(int));
	for (int i = 0; i < amount; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < amount; i++)
	{
		printf("%d ", arr[i]);
	}
	mainFunction(arr,amount);
	for (int i = 0; i < amount; i++) 
	{
		sum += arr[i];
	}
	printf("%d", sum);
}
