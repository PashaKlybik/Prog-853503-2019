/* Найти все натуральные числа, не превосходящие заданного m,
двоичная запись которых представляет собой последовательность
пар нулей и единиц (например: 11001100). Показать десятичную и
двоичную запись этих чисел.*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

//Функция переводит переменные типа char в int.
int CharToInt(char array[]) {
	unsigned int a = 0;
	for (int i = 0; array[i] != '\0'; i++)
	{
		a = 10 * a + (array[i] - '0');
	}
	return a;
}

//Функция проверяет является ли каждая символ введённой переменной числом
bool IsNumeral(char Numeral) {
	if (Numeral >= '0' && Numeral <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Функция находит длинну массива
int ArrayLenght(char array[]) {
	int i = 0;

	while (array[i] != '\0')
	{
		i++;
	}
	return i;
}

//Функция проверяет правильность ввода. 
int InputCheck() {
	char array[100];
	gets(array);

	for (int i = 0; i < ArrayLenght(array); i++)
	{
		if ((array[0] == '0') || (IsNumeral(array[i]) == false))
		{
			printf("The number is entered incorrectly, repeat input.\n");
			return InputCheck();
		}
	}
	return CharToInt(array);
}

//Функция переводит числа из десятичной системы счисления в двоичную.
int DecToBin(unsigned int dec) {
	unsigned int bin = 0;

	for (int i = 0; dec > 0; i++)
	{
		bin += (dec % 2) * int(powl(10, i));
		dec /= 2;
	}
	return bin;
}

//Функция переводит числа из двоичной системы счисления в десятичную.
int BinToDec(unsigned int bin) {
	unsigned int dec = 0;

	for (int i = 1; bin > 0; i *= 2)
	{
		dec += (bin % 10) * i;
		bin /= 10;
	}
	return dec;
}

int main()
{
	unsigned int m, a, b = 11, c;
	bool check = true;

	printf("Insert the number : ");
	//Цикл выпоняется пока не будет введено число, размер которого в двоичной системе счисления находится в диапазон значений переменной типа unsigned int [0, +4 294 967 295]     
	while (true)
	{
		m = InputCheck();
		if (m > 1023)
		{
			printf("Binary record of your number exceeded the range of values of the unsigned int variable, repeat input. \n");
			continue;
		}
		break;
	}
	a = DecToBin(m);
	printf("Binary record of your number: %d\n", a);
	c = BinToDec(b);
	//Поиск чисел удовлетворяющих условию.
	if (m < c)
	{
		printf("Up to %d numbers satisfying the condition do not exist. \n", m);
	}
	else
	{
		printf("Required numbers: \n");
		//Цикл выполняется пока числа удовлетворяющие условию не превышают заданное число m.
		//Переменная b = 11 является двоичной записью первого такого числа.
		//В цикле в переменную b присваиваются остальные числа путём последовательного умножения переменной b на сто  с дальнейшим умножением на сто и прибавлением одинадцати.
		while (m >= c)
		{
			printf("\nin decimal: %d\nin binary: %d\n", c, b);
			if (check == true)
			{
				b = b * 100;
				check = false;
			}
			else
			{
				b = (b * 100) + 11;
				check = true;
			}
			c = BinToDec(b);
		}
	}
	return 0;
}
