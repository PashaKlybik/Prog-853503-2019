
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
	char str_length[256];
	int* arr;
	printf("Length: ");
	gets_s(str_length, 256);
	int length = atof(str_length);
	arr = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf("Repeat: ");
	int repeat;
	scanf_s("%d", &repeat);

	while (repeat)
	{
		int min = arr[0];
		for (int i = 0; i < length; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		for (int i = 0; i < length; i++)
		{
			arr[i] = min-arr[i];
		}
		repeat--;
	}

	//Amount of all elements
	int result = 0;
	for (int i = 0; i < length; i++)
	{
		result += arr[i];
	}
	printf("Result: %d", result);
}