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
	unsigned long long a = 0;
	
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

//Функция проверяет правильность ввода. 
int InputCheck() {
	char array[10];
	gets(array);
	for (int i = 0; i < strlen(array); i++)
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
void DecToBin(int dec) {
	char bin[20];
	int i = 0;
	
	printf("Binary record of your number : ");
	for (i; dec != 0; i++)
	{
		bin[i] = (dec % 2) + 48;
		dec /= 2;

	}
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%c", bin[j]);
	}
	printf("\n");
}


//Функция переводит числа из двоичной системы счисления в десятичную.
int BinToDec(unsigned long long bin) {
	int dec = 0;
	for (int i = 1; bin > 0; i *= 2)
	{
		dec += (bin % 10) * i;
		bin /= 10;
	}
	return dec;
}

int main()
{
	int m, a;
	unsigned long long b = 11, c;
	bool check = true;

	printf("Insert the number : ");
	//Цикл выполняется пока не будет введено число, размер которого в двоичной системе счисления находится в диапазон значений переменной типа unsigned long long [0, 18 446 744 073 709 551 615]     
	while (true)
	{
		m = InputCheck();
		//1048575 - это максимальное десятичное число которое при переводе в двоичную систему счисления находится в этом диапазоне
		if (m > 1048575) 
		{
			printf("Binary record of your number exceeded the range of values of the unsigned long long variable, repeat input. \n");
			continue;
		}
		break;
	}
	DecToBin(m);
	a = BinToDec(b);
	//Поиск чисел удовлетворяющих условию.
	if (m < a) 
	{
		printf("Up to %llu numbers satisfying the condition do not exist. \n", m);
	}
	else {
		printf("\nRequired numbers: \n");
		//Цикл выполняется пока числа удовлетворяющие условию не превышают заданное число m.
		//Переменная b = 11 является двоичной записью первого такого числа.
		//В цикле в переменную b присваиваются остальные числа путём последовательного умножения переменной b на сто  с дальнейшим умножением на сто и прибавлением одиннадцати.
		while (m >= a)
		{
			printf("\nin decimal: %llu\nin binary: %llu\n", a, b);
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
			a = BinToDec(b);
		}
	}
	return 0;
}
