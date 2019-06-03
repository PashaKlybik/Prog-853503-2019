/*
Air Comfort. Компания занимается установкой стеклопакетов; планируется, что после открытия сайта компании
пользователи смогут спроектировать и рассчитать стоимость установки стеклопакетов прямо в интернете.
—Ввод кол-ва окон в квартире.
—Ввод кол-ва балконов.
—Ввод этажа, на котором находится квартира.
—Расчёт и вывод параметров проекта: общая площадь застекления, стоимость застекления окон, стоимость установки
балконной двери, процентная надбавка.
—Вывод общей стоимости проекта.
—Краткая информация о компании и контакты.
—Выход из программы.

Стоимость стандартного оконного пакета (2,15*1,50 м) = $100, включая установку.
Стоимость балконной двери (0,70*2,15 м) = $150, включая установку.
Если квартира находится выше первого этажа, за установку каждого стеклопакета взимается дополнительно 15% его стоимости.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


void printInf();
void WhatAction(const char *, int, const char *);
void PrintCosts(double, double, double, double, double, bool);
int GetNumber();

int main()
{
	setlocale(LC_ALL, "Rus");
	int windowNum, balconyNum, floor;
	double totalCost, area, windowCost, balconyCost, percent;
	bool wantToContinue = true;
	while (wantToContinue)				//пока пользователь хочет продолжать работу в программе
	{
		system("cls");
		totalCost = 0;
		area = 0;
		percent = 0;
		WhatAction("1.Закончить работу в программе.\n2.Ввод количества окон в квартире.\n", 2, "Введите количество окон в квартире: ");
		windowNum = GetNumber();		//ввод количества окон
		area += 2.15*1.5*windowNum;		//добавление к общей площади застекления площадь окон
		windowCost = windowNum * 100;	//расчёт стоимости застекления окон
		WhatAction("1.Закончить работу в программе.\n2.Ввод количества балконов в квартире.\n", 2, "Введите количество балконов в квартире: ");
		balconyNum = GetNumber();		//ввод кол-ва балконов
		area += 0.7*2.15*balconyNum;	//добавление к общей площади застекления площадь балконных стёкол
		balconyCost = balconyNum * 150;	//расчёт стоимости застеклания балконов
		WhatAction("1.Закончить работу в программе.\n2.Ввод номера этажа.\n", 2, "Введите номер этажа, на котором находится квартира: ");
		floor = GetNumber();			//ввод номера этажа
		if (floor > 1)
			percent += 0.15*(windowNum * 100 + balconyNum * 150);		//если этаж > первого, насчитывается надбавка
		totalCost = windowCost + balconyCost + percent;					//расчёт общей стоимости проекта
		PrintCosts(area, windowCost, balconyCost, percent, totalCost, wantToContinue);	//вывод необходимой информации
		wantToContinue = true;
	}
}

int GetNumber()
{
	int number = 0;
	char temp;
	while (scanf_s("%c", &temp))			//посимвольно читаем вводимое число
	{
		if (temp == '\n')					//если строка закончилась, функция возвращает число
			return number;
		if ((temp < '0') || (temp > '9'))	//если встретилась не цифра, сообщить об ошибке и прочитать число ещё раз
		{
			while (temp != '\n')
				temp = getchar();
			printf_s("%s", "Неверный ввод. Попробуйте снова...\n");
			number = 0;
		}
		else
			number = number * 10 + (temp - '0');
	}
}

void printInf()
{
	system("cls");
	//вывод информации о компании
	printf_s("%s", "Компания Air Comfort. Установка стеклопакетов.\n");
	printf_s("%s", "Стоимость стандартного оконного пакета (2,15*1,50 м) = $100, включая установку.\n");
	printf_s("%s", "Стоимость балконной двери (0,70*2,15 м) = $150, включая установку.\n");
	printf_s("%s", "Если квартира находится выше первого этажа, за установку каждого\n");
	printf_s("%s", "стеклопакета взимается дополнительно 15 % его стоимости.\n");
	printf_s("%s", "Вопросы по телефону: +375-44-666-66-66\n");
}

void WhatAction(const char *str, int maxNum, const char *whatWillEnter)
{
	system("cls");
	printf_s("%s", "Выбор действия:\n");
	printf_s("%s", str);
	int number = GetNumber();
	while ((number < 1) || (number > maxNum))				//проверка, введена ли правильная цифра
	{
		printf_s("%s", "Неверный ввод. Попробуйте снова...\n");
		number = GetNumber();
	}
	if (number == 1)
		exit(0);
	else
		printf_s("%s", whatWillEnter);
}

void PrintCosts(double area, double windowCost, double balconyCost, double percent, double totalCost, bool wantToContinue)
{
	system("cls");
	printf_s("%s", "Выбор действия:\n1.Закончить работу в программе.\n");
	printf_s("%s", "2.Общая площадь застекления.\n");
	printf_s("%s", "3.Стоимость застекления окон.\n");
	printf_s("%s", "4.Стоимость установки балкононных дверей.\n");
	printf_s("%s", "5.Процентная надбавка.\n");
	printf_s("%s", "6.Общая стоимость проекта.\n");
	printf_s("%s", "7.Краткая информация о компании и контакты.\n");
	printf_s("%s", "8.Посчитать стоимость проекта для новой квартиры.\n\n");
	int number = GetNumber();				//выбор варианта
	while ((number < 1) || (number > 8))	//если введено число, не входящее в диапазон от 1 до 8, запросить повторный ввод
	{
		printf_s("%s", "Неверный ввод. Попробуйте снова...\n");
		number = GetNumber();
	}
	switch (number)							//действия в соответствии с выбранным вариантом
	{
	case(1):
		exit(0);
		break;
	case(2):
		printf_s("%s%f", "Общая площадь застекления = ", area);
		break;
	case(3):
		printf_s("%s%f", "Стоимость застекления окон = ", windowCost);
		break;
	case(4):
		printf_s("%s%f", "Стоимость установки балконных дверей = ", balconyCost);
		break;
	case(5):
		printf_s("%s%f", "Процентная надбавка = ", percent);
		break;
	case(6):
		printf_s("%s%f", "Общая стоимость проекта = ", totalCost);
		break;
	case(7):
		printInf();
		break;
	case(8):
		wantToContinue = false;
	}
	if (wantToContinue)		//пока пользователь хочет смотреть данные о проекте, давать выбрать вариант
	{
		getch();
		PrintCosts(area, windowCost, balconyCost, percent, totalCost, wantToContinue);
	}
}