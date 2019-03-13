/ * Вариант 22.
Найти все натуральные числа, не превосходящие заданного м,
двоичная запись
пар нулевой и единице (например: 11001100). Показать десятичную и
двоичную запись этих чисел. * /



#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale>
#include <ctype.h>
#include <Windows.h>
#include <stdbool.h>

//Функция переводит числа из двоичной системы счисления в десятичную.
int BinToDec(long int bin) {
	long int dec = 0;
	for (int i = 1; bin > 0; i *= 2)
	{
		dec += (bin % 10) * i;
		bin /= 10;
	}
	return dec;
}

//Функция переводит числа из десятичной системы счисления в двоичную.
int DecToBin(long int dec) {
	long int bin = 0;
	for (int i = 0; dec > 0; i++)
	{
		bin += (dec % 2) * powl(10, i);
		dec /= 2;
	}
	return bin;
}

//Функция переводит переменные типа char в int.
int CharToInt(char array[]) {
	long int a = 0;
	for (int i = 0; array[i] != '\0'; i++)
	{
		a = 10 * a + (array[i] - '0');
	}
	return a;
}

//Функция проверяет является ли каждая символ введённой переменной числом
bool IsNumeral(char Numeral) {
	if (Numeral >= '0' && Numeral <= '9') {
		return true;
	}
	else {
		return false;
	}
}

//Функция проверяет правильность ввода. 
int InputCheck() {
	char array[100];
	gets_s(array);
	for (int i = 0; i < strlen(array); i++)
	{
		if ((array[0] == '0') || (IsNumeral(array[i]) == false)) {
			printf("Число введено неправильно, пожалуйста повторите ввод.\n");
			return InputCheck();
		}
	}
	return CharToInt(array);
}

int main()
{
	//Русификация консоли.
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	long int m, a, b = 11, c;
	bool check = true;

	printf("Введите число: ");
	m = InputCheck();
	a = DecToBin(m);
	printf("Двоичная запись вашего числа: %d\n", a);
	c = BinToDec(b);
	//Поиск чисел удовлетворяющих условию.
	if (m < c) {
		printf("В пределах до %d чисел удовлетворяющих условию не существует.\n", m);
	}
	else {
		printf("искомые числа:\n");
		while (m >= c)
		{
			printf("\nв десятичной: %d\nв двоичной: %d\n", c, b);
			if (check == true) {
				b = b * 100;
				check = false;
			}
			else {
				b = (b * 100) + 11;
				check = true;
			}
			c = BinToDec(b);
		}
	}
	return 0;
}

