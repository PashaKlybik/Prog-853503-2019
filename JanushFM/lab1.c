// Вариант 29
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int number;
	do
	{
		printf("Введите натуральное число: ");
		scanf_s("%d", &number);
		if (number<=0) printf("Ваше число не натуральное, попробуйте ещё раз\n");
	} while (number <= 0);
	char str[100];
	_itoa_s(number, str, 10);
	bool incr = true, red = true, wrong = false;
	for (int i = 0; str[i+1] != '\0'; i++)
	{
		if (str[i + 1] > str[i]) //проверка на возрастание
		{
			red = false;
		}
		else if (str[i + 1] < str[i]) //проверка на убывание
		{
			incr = false;
		}
		if (str[i + 1] == str[i])//в случае если идут подряд одинаковые числа
		{
			wrong = true;
			break;
		}
		if (red == false && incr == false)//если только часть числа упорядочена 
		{
			wrong = true;
			break;
		}
	}
	if (wrong == true || str[1] =='\0') printf("Ваша число не является упорядоченными по возврастанию, или убыванию");
	else
	{
		if (incr) printf("Цифры упорядочены по возрастанию");
		else if (red) printf("Цифры упорядочены по убыванию");
	}
	return 0;
}
