//variant 25
//sakovich vlad
#include <stdio.h>
#include <stdlib.h>

int HowMany(int a)
{
	int b = 0;
	while (a)
	{
		a /= 2;
		b++;
	}
	return b;
}
void perevod(int *arr, int a, int num)
{

	for (int i = 0; i < a; i++)
	{
		arr[i] = num % 2;
		num /= 2;
	}
}
void out(int num, int *arr, int a)
{
	int ultra = 0, b = a - 1, a1 = a / 2;
	for (int i = 0; i < a1; i++)
	{
		if (arr[i] != arr[b]) {
			ultra = 1;
		}
		b--;
	}
	if (ultra == 0)
	{
		printf("%d  ", num);
		for (int i = 0; i < a; i++) {
			printf("%d", arr[i]);
		}
		printf("\n");
	}
}

int main()
{
	int m, kolvo, *arr;
	printf("Input m\n");
	scanf_s("%d", &m);
	for (int i = 1; i < m; i++)
	{
		kolvo=HowMany(i);
		arr = (int*)malloc(kolvo* sizeof(int));
		perevod(arr, kolvo, i);
		out(i, arr, kolvo);
		free(arr);
	}
}
