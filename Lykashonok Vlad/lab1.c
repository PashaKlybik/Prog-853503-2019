#include <stdio.h>
//14 вариант

_Bool isPerfect(int);

int main()
{
	long int max;
	printf_s("Input border\n");
	scanf_s("%i", &max);

	for (int number = 0; number < max; number += 2)
	{
		//все идеальные числа чётные, поэтому ^ смотрим чётные
		//просматривает каждое число на идеальность
		if (isPerfect(number) && number != 0)
		{
			printf_s("%d\n", number);
		}
	}
	printf_s("done");
	scanf_s("%i", &max);

	return 0;
}

_Bool isPerfect(int number)
{
	int divider_sum = 0;
	for (int divider = 1; divider < number - 1; divider++)
	{
		// сумма делителей
		if (!(number%divider))
			divider_sum += divider;
	}
	//если сумма делителей равна числу, то вернёт 1
	return number == divider_sum;
}


//            6,
//           28,
//          496,
//        8 128,
//   33 550 336, Уже на этом числе время проверки > 10 минут (действительно в результате находит)
//8 589 869 056 
