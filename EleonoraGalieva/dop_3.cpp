#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

char IntToChar(int i)
{
	char k;
	switch (i)
	{
		case 0:k = '0'; break;
		case 1:k = '1'; break;
		case 2:k = '2'; break;
		case 3:k = '3'; break;
		case 4:k = '4'; break;
		case 5:k = '5'; break;
		case 6:k = '6'; break;
		case 7:k = '7'; break;
		case 8:k = '8'; break;
		case 9:k = '9'; break;
	}
	return k;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const long int size = 1000000;
	char num[size];
	bool flag = true;
	while (flag)
	{
		printf("\nВведите строку:\n");
		gets_s(num);
		for (int i = 0; i < strlen(num); i++)
		{
			if ((num[i] >= 'A'&&num[i] <= 'z') == false)
			{
				flag = true;
				printf("\nСтрока должна содержать только буквы!");
				break;
			}
			else flag = false;
		}
	}
	int amount = 1;
	char* result = (char*)malloc(strlen(num) * sizeof(char) + 1);
	int j = 0;
	for (int i = 0; i < strlen(num); i++)
	{
		char letter = num[i];
		if (num[i + 1] == num[i])
		{
			amount++;
			continue;
		}
		if (amount > 2)
		{
			result[j] = IntToChar(amount);
			j++;
			result[j] = letter;
			j++;
			amount = 1;
		}
		else if (amount==2)
		{
			while (amount != 0)
			{
				result[j] = num[i-1];
				j++;
				amount--;
			}
			amount = 1;
		}
		else
		{
			result[j] = letter;
			j++;
		}
	}
	result[j]= '\0';
	printf("\nРезультат: %s\n", result);
	free(result);
	_getch();
	return 0;
}