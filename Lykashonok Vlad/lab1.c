#include <stdio.h>
#include <math.h>
//14 вариант

_Bool isPerfect(int);

int main()
{
	long int max;
	printf_s("Input border\n");
	scanf_s("%i", &max);

	for (int number = 1; number < max; number++)
	{
		if (isPerfect(number))
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
	int divider_sum = 1, sqrt_num = (int)sqrt(number) + 1;
	for (int i = 2; i< sqrt_num; i++)
	{
		//находим у числа все делители
		if (number%i == 0 && i * i != number && i != number)
		{
			//если делитель, то прибавляем
			divider_sum += i;
			//чтобы само число не входило в делители
			divider_sum += number / i;
			if (divider_sum > number) return 0;
		}
		
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
