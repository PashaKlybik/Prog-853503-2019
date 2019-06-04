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

void Set(char* num, long int& x1, long int& y1, long int &x2,long int& y2)
{
	int tab_count = 0;
	long int number = 0;
	for (int i = 0; i < strlen(num); i++)
	{
		if (num[i] >= '0'&&num[i] <= '9')
		{
			number = number * 10 + Switch(num[i]);
			if (number > pow(10, 8) || number < 0)
				throw '1';
		}
		else if (num[i] == ' ')
		{
			tab_count++;
			if (tab_count == 1)
			{
				x1 = number;
				if (x1 >pow(10,6)||x1<-pow(10,6))
				{
					throw '1';
				}
				number = 0;
			}
			else if (tab_count == 2)
			{
				y1 = number;
				if (y1 > pow(10, 6) || y1 < -pow(10, 6))
				{
					throw '1';
				}
				number = 0;
			}
			else if (tab_count == 3)
			{
				x2 = number;
				if (x2 > pow(10, 6) || x2 < -pow(10, 6) || x2 < x1)
				{
					throw '1';
				}
				number = 0;
			}
			else if (tab_count == 4)
			{
				y2 = number;
				number = 0;
			}
			else if (tab_count > 4 || tab_count == 0) throw 1;
		}
		else
		{
			throw 1;
		}
	}
}

void Set(char* num, long int& x1, long int& y1, long int &x2)
{
	int tab_count = 0;
	long int number = 0;
	for (int i = 0; i < strlen(num); i++)
	{
		if (num[i] >= '0'&&num[i] <= '9')
		{
			number = number * 10 + Switch(num[i]);
			if (number > pow(10, 8) || number < 0)
				throw '1';
		}
		else if (num[i] == ' ')
		{
			tab_count++;
			if (tab_count == 1)
			{
				x1 = number;
				if (x1 > pow(10, 6) || x1 < -pow(10, 6))
				{
					throw '1';
				}
				number = 0;
			}
			else if (tab_count == 2)
			{
				y1 = number;
				if (y1 > pow(10, 6) || y1 < -pow(10, 6))
				{
					throw '1';
				}
				number = 0;
			}
			else if (tab_count == 3)
			{
				x2 = number;
				if (x2 > pow(10, 6) || x2 < -pow(10, 6) || x2 < x1)
				{
					throw '1';
				}
				number = 0;
			}
			else if (tab_count > 3 || tab_count == 0) throw 1;
		}
		else
		{
			throw 1;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char num1[40];
	char num2[20];
	bool cycle = true;
	long int x1 = 0, y1 = 0, x2 = 0, y2 = 0,px=0,py=0,pr=0;
	while (cycle)
	{
		printf("\nВведите X1, Y1, X2, Y2 через пробел:\n");
		gets_s(num1);
		try
		{
			Set(num1, x1, y1,x2,y2);
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
	cycle = true;
	while (cycle)
	{
		printf("\nВведите Px, Py, Pr через пробел:\n");
		gets_s(num2);
		try
		{
			Set(num2,px,py,pr);
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
	for (long int i = y1; i <= y2; i++)
	{
		for (long int j = x1; j <= x2; j++)
		{
			if (sqrt(pow((px - j), 2) + pow((py - i), 2)) > pr)
				sum ++;
		}
	}
	printf("Количество деревьев, которые не будут политы:\n%d", sum);
	_getch();
	return 0;
}
