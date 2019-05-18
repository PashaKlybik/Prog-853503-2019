#include <stdio.h>
#include <malloc.h>

int main()
{
	int n;
	bool flag=1;
	printf_s("input size of array: ");
	scanf_s("%d", &n);
	int *arr;
	int *arr2=NULL;
	arr = (int*)malloc(n * sizeof(int));
	printf_s("input elements\n");
	for (int i = 0; i < n; i++)
	{
		
		scanf_s("%p", &arr[i]);
		
	}
	printf_s("input ammount of iterations: ");
	int amm;
	scanf_s("%d", &amm);
	for(int j = 0;j<amm;j++)
	{
		flag = 0;
		int min = arr[0];
		for (int i = 1; i < n; i++)
			if (arr[i] < min)
				min = arr[i];
		
		arr2= (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			arr2[i] = min - arr[i];
		}
		j++;
		free(arr);
		if (j < amm)
		{
			flag = 1;
			int min = arr2[0];
			for (int i = 1; i < n; i++)
				if (arr2[i] < min)
					min = arr2[i];
			int *arr;
			arr = (int*)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++)
			{
				arr[i] = min - arr2[i];
			}
			free(arr2);
		}
	}
	int sum = 0;
	if (!flag)
	{
		for (int i = 0; i < n; i++)
			sum += arr2[i];
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
		}
	}
	printf_s("%d\n", sum);
}

