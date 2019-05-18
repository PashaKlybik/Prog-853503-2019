#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

int Switch(char s)
{
	int k;
	switch (s)
	{
		case '0':k = 0; break;
		case '1':k = 1; break;
		case '2':k = 2; break;
		case '3':k = 3; break;
		case '4':k = 4; break;
		case '5':k = 5; break;
		case '6':k = 6; break;
		case '7':k = 7; break;
		case '8':k = 8; break;
		case '9':k = 9; break;
	}
	return k;
}

long int StrToLong(char*num)
{
	long int N = 0;
	if (strlen(num) > 5)throw '1';
	for (int i = 0; i < strlen(num); i++)
	{
		if (num[i] >= '0'&&num[i] <= '9')
			continue;
		else throw 1;
	}
	for (int i = 0; i < strlen(num); i++)
	{
		N = N * 10 + Switch(num[i]);
	}
	return N;
}

void SetArray(char*num, long int *A)
{
	int array_index = 0;
	int array_value = 0;
	bool minus = false;
	for (int i = 0; i < strlen(num); i++)
	{
		if (num[i] >= '0'&&num[i] <= '9')
		{
			array_value = array_value * 10 + Switch(num[i]);
			if (array_value >= 1000 || array_value <= -1000)
				throw '1';
		}
		else if (num[i] == ' ')
		{
			if (minus)
				array_value *= (-1);
			A[array_index] = array_value;
			array_index++;
			array_value = 0;
			minus = false;
		}
		else if (num[i] == '-')
		{
			minus = true;
		}
		else throw 1;
	}
}

void ArraySort(long int*&A,long int array_size)
{
	for (int i = 1; i < array_size; i++)
	{
		int x = A[i];
		int j = i - 1;
		while (x < A[j])
		{
			A[j + 1] = A[j];
			j--;
			if (j <= 0) break;
		}
		A[j + 1] = x;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	char num[10000];
	bool cycle = true;
	long int array_size = 0;
	long int *A = NULL;
	while (cycle)
	{
		printf("\nВведите размер массива:\n");
		gets_s(num);
		try
		{
			array_size = StrToLong(num);
			A = (long int*)malloc(array_size * sizeof(long int));
			cycle = false;
		}
		catch (int&)
		{
			printf("Строка должна содержать только числа!");
			num[0] = '\0';
		}
		catch (char&)
		{
			printf("Введена слишком длинная строка!");
			num[0] = '\0';
		}
	}
	for (int i = 0; i < array_size; i++)
	{
		A[i] = 0;
	}
	num[0] = '\0';
	cycle = true;
	while (cycle)
	{
		printf("\nВведите элементы массива. Если элементов будет меньше, чем размер массива, то оставшиеся заполн-ся нулями. \n");
		gets_s(num);
		try
		{
			SetArray(num, A);
			cycle = false;
		}
		catch (int&)
		{
			printf("\nБыл введен неверный символ!\n");
		}
		catch (char&)
		{
			printf("\nБыло введено число, не входящее в диапазон!\n");
		}
	}
	cycle = true;
	num[0] = '\0';
	long int number_of_changes = 0;
	while (cycle)
	{
		printf("\nВведите количество преобразований:\n");
		gets_s(num);
		try
		{
			number_of_changes = StrToLong(num);
			cycle = false;
		}
		catch (int&)
		{
			printf("Строка должна содержать только числа!");
			num[0] = '\0';
		}
		catch (char&)
		{
			printf("Введена слишком длинная строка!");
			num[0] = '\0';
		}
	}
	long int *B = (long int*)malloc(array_size * sizeof(long int));
	bool a = true;
	bool b = false;
	int sum=0;
	for (int i = 0; i < array_size; i++)
	{
		sum += A[i];
	}	
	for (int i = number_of_changes; i >0; i--)
	{
		if (a)
		{
			sum = 0;
			ArraySort(A, array_size);
			for (int i = 0; i < array_size; i++)
			{
				B[i] = A[0] - A[i];
				sum += B[i];
			}
			for (int i = 0; i < array_size; i++)
			{
				A[i] = 0;
			}
			a = false;
			b = true;
		}
		else if (b)
		{
			sum = 0;
			ArraySort(B, array_size);
			for (int i = 0; i < array_size; i++)
			{
				A[i] = B[0] - B[i];
				sum += A[i];
			}
			for (int i = 0; i < array_size; i++)
			{
				B[i] = 0;
			}
			a = true;
			b = false;
		}
	}
	printf("\nСумма элементов конечного массива: %d\n", sum);
	free(A);
	free(B);
	_getch();
	return 0;
}