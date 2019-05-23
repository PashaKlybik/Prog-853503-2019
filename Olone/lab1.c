// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//27 variant, 853503, Tikhonovich Dmitry

#include "pch.h"
#include <stdio.h>

int main()
{
	int first = 0, last = 0, i, copy, A[10], max = 0, rightnumber;
	printf("Input first and last numbers of interval: ");
	scanf_s("%d", &first);
	scanf_s("%d", &last);
	while (first != last + 1)  //search right number
	{
		i = 0;
		copy = first;
		while (copy != 0) //convert to 2 number system
		{
			if (copy % 2 == 1) i++;
			copy /= 2;
		}
		if (i > max)
		{
			max = i;
			rightnumber = first;
		}
		first++;
	}
	printf("%d\n", rightnumber);
	i = 0;
	while (rightnumber != 0) //convert to 2 number system right number
	{
		A[i] = rightnumber%2;
		i++;
		rightnumber /= 2;
	}
	for (copy = --i; copy >= 0; copy--) printf("%d", A[i]);
}

