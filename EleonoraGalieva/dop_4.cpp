#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
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

void Set(char* num,long int& from,long int& to, long int &price)
{
	int tab_count = 0;
	long int number = 0;
	for(int i=0;i<strlen(num);i++)
	{ 
		if (num[i] >= '0'&&num[i] <= '9')
		{
			number = number * 10 + Switch(num[i]);
			if (number > pow(10, 8)||number<0)
				throw '1';
		}
		else if (num[i] == ' ')
		{
			tab_count++;
			if (tab_count == 1)
			{
				from = number;
				if (from < 1)
				{
					throw '1';
				}
				number = 0;
			}
			else if (tab_count == 2)
			{
				to = number;
				if (to <1|| to < from)
				{
					throw '1';
				}
				number = 0;
			}
			else if (tab_count == 3)
			{
				price = number;
				number = 0;
			}
			else if (tab_count > 3 || tab_count == 0) throw 1;
		}
		else
		{
			number = 0;
			from = 0;
			to = 0;
			price = 0;
			throw 1;
		}
	}
}

long int TurnAround(long int number)
{
	long int result = 0;
	while (number != 0)
	{
		result = 10 * result + number % 10;
		number /= 10;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char num[30];
	bool cycle = true;
	long int from = 0;
	long int to = 0;
	long int price = 0;
	while (cycle)
	{
		printf("\nВведите 3 целых числа через пробел:\n");
		gets_s(num);
		try
		{
			Set(num, from, to, price);
			cycle = false;
		}
		catch (int&)
		{
			printf("\nБыл введен неверный символ!\n");
		}
		catch (char&)
		{
			printf("\nБыло введено число, не совпадающее с требованиями задания!\n");
		}
	}
	int sum = 0;
	for (long int i = from; i <= to; i++)
	{
		if (abs(i - TurnAround(i)) <= price)
			sum++;
		else continue;
	}
	printf("%d", sum);
	_getch();
	return 0;
}
