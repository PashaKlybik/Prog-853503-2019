// Lab2_V1 Условие:
// Тетраэдр. Разработать программу, меню которой позволяет выполнить следующие функции :
// Ввод длины ребра тетраэдра.
// Вывод общей длины всех ребер тетраэдра.
// Вывод площади всех граней тетраэдра.
// Вывод объема тетраэдра.
// Вывод высоты тетраэдра.
// Вывод радиуса вписанного шара.
// Информация о версии и авторе программы.
// Выход из программы.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int mainMenu(); // Функция меню программы
void Task(); // Функция, в которой выполняется условие задания
bool IsNumber(char* str); // Проверка на ввод числа
int main()
{
	for (;;)  // Бесконечный цикл. Работает пока пользователь не решит закончить работу с программой[Ввод цифры 2]
	{
		switch (mainMenu()) // Вывод меню на экран. Возвращает номер пункта меню, выбранного пользователем
		{
		case 1:
			system("cls"); // Здесь и далее очистка консоли
			Task(); // Функция выполнения задания
			break;
		case 2:
			system("cls");
			printf_s("Thank you for using our program!\nAuthor: Evgeniy Vashinko\nVersion: 1.0.2\n");
			system("pause");
			return 0;
		default:  // В случае неверного ввода сообщает об этом пользователю и просит повторить ввод
			system("cls");
			printf_s("\n---Wrong input---\n\n");
			break;
		}
	}
}

int mainMenu()
{
	printf_s("Enter 1 to calculate the parameters");
	printf_s("\nEnter 2 to exit\n");
	int num;
	scanf_s("%d", &num);
	return num;
}

void Task()
{
	char str[10];
	float Side;  // Сторона тетраэдра
	printf_s("Enter the side of tetrahedron: ");
	scanf_s("%s", str, 10); // Ввод стороны
	if (IsNumber(str) == false || atoi(str) <= 0) // В случае неверного ввода сообщает об этом пользователю
	{
		system("cls");
		printf_s("\n---Wrong input---\n");
	}
	else
	{
		Side = atof(str);
		float P = 6 * Side;
		printf_s("P =  %f", P); // Сумма сторон
		printf_s("\nS = %f", powl(Side, 2) * sqrt(3)); // Площадь поверхности
		printf_s("\nr = %f", Side * sqrt(6) / 12); // Радиус вписанной окружности
		printf_s("\nR = %f", Side * sqrt(6) / 4); // Радиус описанной окружности
		printf_s("\nH = %f", Side * sqrt(6) / 3); // Высота тетраэдра
		printf_s("\nV = %f", powl(Side, 3) * sqrt(2) / 12); // Объем тетраэдра
	}
	printf_s("\n\n");
}

bool IsNumber(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

