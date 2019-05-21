#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

char* INput(char *initStr); // функция для ввода числа через массив char
long long int charToint(char *initStr); // перевод char to int
int happydelitel(long long int); // проверка числа на "счастливость"
long long int mindel(long long int); // нахождение минимального делителя числа (большего 1)

int main(void) {
	char *inputstring = NULL; // ввод строки
	printf("Enter the original number:  ");
	inputstring = INput(inputstring);
	long long nomber = charToint(inputstring); // преобразование в число
	int kolvo = 0;
	if (happydelitel(nomber))
		kolvo += 1; // проверка на "счастливость" числа
	for (int step = mindel(nomber); step <= nomber / step; step++) //подсчет количества счастливых делителей
	{
		if (nomber % step == 0) {
			if (happydelitel(step)) {
				kolvo += 1;
			}
			long temp = nomber / step;
			if (happydelitel(temp)) {
				kolvo += 1;
			}

		}

	}
	printf("The number of almost happy divisors is equal to: %d", kolvo);
	// вывод результатов
	return 0;
}

char* INput(char* string)
	// ввод безразмерной строки с динамическим выделением памяти
{
	int size = 1, i = 0;
	string = (char*)malloc(sizeof(char) * size);
	while (1) {
		*(string + i) = getchar();
		if (*(string + i) == '\n' || *(string + i) > '9' || *(string + i) < '0')
		{
			*(string + i) = '\0';
			break;
		}
		size++;
		string = (char*)realloc(string, sizeof(char) * size);
		i++;
	}
	return string;
}

long long int charToint(char* initStr) // преобразование char в int
{
	int size = strlen(initStr);
	// преобразование по полавинам, так как многие стандартные функции не работают с long long
	long long nomber = 0;
	int stepen = size / 2;

	for (int temp = 0; temp < stepen; temp++) {
		nomber += (*(initStr + temp) - '0') * pow(10, stepen - temp - 1);
	}
	int stepenNomber = size - stepen;
	nomber = nomber * powl(10, stepenNomber);

	for (int temp = size - 1, i = 0; temp >= stepen; temp--, i++) {
		nomber += (*(initStr + temp) - '0') * pow(10, i);
	}
	return nomber;
}

int happydelitel(long long int delitel) // проверка на счастливость числа
{
	while (delitel > 0) {
		if (delitel % 10 == 4 || delitel % 10 == 7)
			return 1;
		else
			delitel /= 10;
	}
	return 0;
}

long long int mindel(long long int number)
	// нахождение минимального делителя для данного числа
{
	for (int i = 2; i < number; i++) {
		if (number % i == 0)
			return i;
	}
	return number;
}
