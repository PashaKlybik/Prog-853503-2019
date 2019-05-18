#include <tchar.h>
#include <stdio.h>
#include <malloc.h>

int main()
{
	int array_size, *A, *B, i, j, min, sum = 0, reiteration;
	printf("write the size of your array:\n");
	while (1)//Бесконечный цикл для проверки правильности ввода размера массива
	{
		scanf("%d",&array_size);
		if (array_size <= 0)
		{
			printf("array size cannot be less than or equal to zero");
			continue;
		}
		break;
	}

	A = (int*)malloc(array_size * sizeof(int));//создание массива A
	for ( i = 0 ; i < array_size; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &A[i]);//Ввод элементов для массива A
	}

	printf("Write the number of reiterations:\n");
	while (1)
	{
		scanf("%d",&reiteration);
		if (reiteration < 0)
		{
			printf("reiteration size cannot be less than zero");
			continue;
		}

		else if (reiteration == 0)
		{
			for (i = 0; i < array_size; i++)
			{
				sum = sum + A[i];//Считаю сумму
			}

			printf("%d",sum);//Вывод результата

            system("pause");
			return 0;
		}
		break;
	}
///////////////////////////////Начало цикла/////////////////////////////////////
	for (j = 0; j < reiteration; j++)
	{
		min = A[0];
		for (i = 0; i < array_size; i++)
		{
			if (A[i] < min)
			{
				min = A[i];//нахожу минимальный элемент массива
			}
		}

		B = (int*)malloc(array_size * sizeof(int));//создание массива B
		for (i = 0; i < array_size; i++)
		{
			B[i] = min - A[i];//Присваиваю значения элементам массива
		}

		for (i = 0; i < array_size; i++)
		{
			A[i] = B[i];
		}
	}
///////////////////////////////Конец цикла//////////////////////////////////////

	for (i = 0; i < array_size; i++)
	{
		sum = sum + B[i];//Считаю сумму
	}

	printf("%d",sum);//Вывод результата

////////////////////////////////////////////////////////////////////////////////
	free(A);//Чищу память
	free(B);//Чищу память
	system("pause");
	return 0;
}
