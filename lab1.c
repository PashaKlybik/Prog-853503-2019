// Вариант 29
#include "pch.h"
#include <string>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int number;
	printf("Введите натуральное число: ");
	scanf_s("%d", &number);
	printf("\n");
	char str[100];
	_itoa_s(number, str, 10);					
	int size = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		size++;
	}	
	bool incr = true, red = true,wrong=false;
	for (int i = 0; str[i]!='\0'; i++)
	{
		if (str[i + 1] > str[i] && str[i + 1] != '\0')
		{
			red = false;
		}
		else if (str[i + 1] < str[i] && str[i + 1] != '\0')
		{
			incr = false;
		}
		else if (str[i + 1] == str[i])
		{
			wrong = true;
			break;
		}
		else if (red == false && incr == false)
		{
			wrong = true;
			break;
		}
	}
	if (wrong == true || size<2) printf("Ваша число не является упорядоченными по возврастанию, или убыванию");
	else
	{
		if (incr) printf("Цифры упорядочены по возрастанию");
		else if (red) printf("Цифры упорядочены по убыванию");
	}
	return 0;
}