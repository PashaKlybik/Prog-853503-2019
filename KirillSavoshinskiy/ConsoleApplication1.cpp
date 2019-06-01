/*Вариант 10
Для фирмы,  занимающаяся «перегонкой» автомобилей из Европы, написать программу для вычисления 
ценя перегонки, цены растамаживания и полной цены(перегока + цена авто + тамож. пошлина) */

#include <iostream>
#include <string>
using namespace std;

void Calc(int car_price, int year, int way, float V);

bool Check(int &car_price, int &year, int &way, float &V);  //Функция проверки ввода

int main()
{
	int car_price = 0, year = 0, way = 0;
	float V = 0;
	int key = 1;
	while (key == 1)
	{
		system("cls");
		cout << "Information about the author: savosh28@gmail.com \nVersion: 1.0" << endl;
		if (Check(car_price, year, way, V))
		{
			Calc(car_price, year, way, V);
		}
		else
		{
			cout << "Invalid input" << endl;
		}
		cout << "If you want to calculate again press 1, else press 0:";
		cin >> key;
	}
}

void Calc(int car_price, int year, int way, float V)
{
	float run_price, duty, full_price;
	int age;
	run_price = way * 0.5;                                        
	age = 2019 - year;                             //Вычисление возраста
	V = 1000 * V;                                  //Перевод объёма в куб. см.

	if (age <= 3)
	{
		duty = V * 0.6;
	}
	else if (age > 3 && age <= 10 && V < 2500)
	{
		duty = V * 0.35;
	}
	else if (age > 3 && age <= 10 && V >= 2500)
	{
		duty = V * 0.6;
	}
	else if (age > 10 && age <= 14)
	{
		duty = V * 0.6;
	}
	else
	{
		duty = V * 2;
	}

	full_price = duty + run_price + car_price;
	cout << endl;
	cout << "Cost of driving a car:" << run_price << endl;
	cout << "Cost of customs duty:" << duty << endl;
	cout << "Full price:" << full_price << endl;
}

bool Check(int &car_price, int &year, int &way, float &V)
{
	bool check_price, check_year, check_V, check_way;
	string price_str;
	string year_str;
	string way_str;
	string V_str;
	cout << "Enter car price:";
	cin >> price_str;
	cout << "Enter year:";
	cin >> year_str;
	cout << "Enter run distance:";
	cin >> way_str;
	cout << "Enter capacity in liters:";
	cin >> V;
	V_str = to_string(V);
 
	for (int i = 0; i < price_str.length(); i++)
	{
		if (price_str[i] == '.'|| price_str[i] == ',')
		{
			check_price = false;
		}
		else
		{
			check_price = true;
			int digit = (int)price_str[i] - (int)'0';
			car_price = car_price * 10 + digit;
		}
	}

	for (int i = 0; i < year_str.length(); i++)
	{
		if (year_str[i] == '.' || year_str[i] == ',')
		{
			check_year = false;
		}
		else
		{
			check_year = true;
			int digit = (int)year_str[i] - (int)'0';
			year = year * 10 + digit;

		}
	}

	for (int i = 0; i < way_str.length(); i++)
	{
		if (way_str[i] == '.' || way_str[i] == ',')
		{
			check_way = false;
		}
		else
		{
			check_way = true;
			int digit = (int)way_str[i] - (int)'0';
			way = way * 10 + digit;

		}
	}

	for (int i = 0; i < V_str.length(); i++)
	{
		if (V_str[i] == ',')
		{
			check_V = false;
		}
		else
		{
			check_V = true;
		}
	}

	if (check_price == true && check_year == true && check_way == true && check_V == true )
	{
		return true;
	}
	else
	{
		return false;
	}
}

 
