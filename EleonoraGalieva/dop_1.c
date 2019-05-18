#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

long long Input()
{
	long long result = 0;
	while (1)
	{
		int wrong_symbol = FALSE;
		size_t length = 1;
		char ch, *str = (char*)malloc(length * sizeof(char));
		while ((ch = getchar()) != '\n')
		{
			str[length - 1] = ch;
			length++;
			str = (char*)realloc(str, length * sizeof(char));
		}
		str[length - 1] = '\0';
		for (int i = 0; i < length - 1; i++)
		{
			if ((str[i] >= '0' && str[i] <= '9'))
			{
				continue;
			}
			else
			{
				printf("\nНекорректный ввод! Попробуйте еще раз:\n");
				str[0] = '\0';
				wrong_symbol = TRUE;
				break;
			}
		}
		if (!wrong_symbol)
		{
			result = atoll(str);
			break;
		}
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	long long N;
	N = Input();
	int cycle = TRUE;
	int sum = 0;
	for (long long i = 1; i <= N; i++)
	{
		if (N%i == 0)
		{
			long long num = i;
			while (num > 0)
			{
				if (num % 10 == 4 || num % 10 == 7)
					sum++;
				num /= 10;
			}
		}		
	}
	printf("\nКоличество делителей числа, которые являются почти счастливыми:%d\n", sum);
	system("pause");
	return 0;
}