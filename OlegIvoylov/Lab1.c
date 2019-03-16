/* 11. Определить k-ю цифру последовательности 14916253649...,
в которой выписаны подряд квадраты натуральных чисел. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	unsigned long digits_num = 0;
	short numeric;
	printf("Дана последовательность квaдратов 14916253649...\nВыберите номер цифры: ");
	scanf("%i", &k);
	int i = 0;
	for (unsigned long val = 0; digits_num < k; ++i, val = 0) // расчёт общего количества разрядов
	{
		val = pow((i + 1), 2);
		do
		{
			val /= 10;
			++digits_num;
		} while (val);
	}
	numeric = (short)(pow(i, 2) / pow(10, digits_num - k)) % 10; // нахождение конкретного разряда в квадрате числа
	printf("k-я цифра последоватеьности — %i\n\n", numeric);
	system("pause");
	return 0;
}
