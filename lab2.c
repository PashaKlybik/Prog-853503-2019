//Треугольник. Разработать программу, меню которои? позволяет выполнить следующие функции
//• Ввод координат вершин треугольника
//• Определить вид треугольника (правильныи?, прямоугольныи?,равнобедренныи?, произвольного вида).
//• Вывод периметра треугольника
//• Вывод площади треугольника.
//• Вычислить и вывести радиусы вписанноий и описанной вокруг треугольника окружностей.
//• Выполнено в visual studio, Акулич  Константин, 853503, вариант 12

#include <stdio.h>
#include <math.h> 
#include <locale.h>

double check(float);

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice = 0;
	double  x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, Half_meter = 0, Perimetr = 0, side_one = 0, side_two = 0, side_three = 0, Area = 0, small_radius = 0, big_radius = 0;
	
	do
	{
		printf("Определить вид треугольника -- 1\nВывести периметр треугольника -- 2\nВывести площадь треугольника -- 3\nВывести значения радиусов треугольника -- 4\nВывести информацию об авторе программы -- 5\nВвести координаты точки -- 6\nЗакончить процесс -- 9\n");
		choice = check(choice);
		system("cls");
		if (choice == 1)
		{
			if (side_one == side_two || side_one == side_three || side_two == side_three)
			{
				printf("Треугольник является равнобедренным\n");
			}
			if (side_one == side_two && side_two == side_three)
			{
				printf("Треугольник является правильным\n");
			}
			if (pow(side_one, 2) + pow(side_two, 2) == pow(side_three, 2) || pow(side_one, 2) + pow(side_three, 2) == pow(side_two, 2) || pow(side_three, 2) + pow(side_two, 2) == pow(side_one, 2))
			{
				printf("Треугольник является прямоугольным\n");
			}
			if(side_one!=side_two && side_one!=side_three)
			{
				printf("Треугольник является произвольным\n");
			}
		}
		if (choice == 2)
		{
			Perimetr = side_one + side_two + side_three;
			printf("Периметр = %f\n", Perimetr);
		}
		if (choice == 3)
		{
			Half_meter = Perimetr / 2;
			Area = sqrt(Half_meter * (Half_meter - side_one) * (Half_meter - side_two) * (Half_meter - side_three));//Площадь считаем по формуле Герона
			printf("Площадь = %f\n", Area);
		}
		if (choice == 4)
		{
			small_radius = (2 * Area) / (side_one + side_two + side_three);
			printf("Радиус вписанной окружности = %f\n", small_radius);
			big_radius = (side_one * side_two * side_three) / (4 * Area);
			printf("Радиус описанной окружности = %f\n", big_radius);
		}
		if (choice == 5)
		{
			printf("Автор программы -- Акулич Константин Андрееевич, родился 3 июня 2000 года, имеет среднее образование, ГОДЕН В АРМИЮ ВО ВСЕ ВОЙСИКА\n");
		}
		if (choice == 6)
		{
			printf("Введите координаты первой точки: \n");
			x1 = check(x1);
			y1 = check(y1);
			printf("Введите координаты второй точки: \n");
			x2 = check(x2);
			y2 = check(y2);
			printf("Введите координаты третей точки: \n");
			x3 = check(x3);
			y3 = check(y3);
			side_one = sqrt(abs(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
			side_two = sqrt(abs(pow((x3 - x2), 2) + pow((y3 - y2), 2)));
			side_three = sqrt(abs(pow((x3 - x1), 2) + pow((y3 - y1), 2)));
			printf("Первая сторона = %f\n", side_one);
			printf("Вторая сторона = %f\n", side_two);
			printf("Третья сторона = %f\n", side_three);
		}
	} while (choice != 9);

	return 0;
}

double check(float n)
{
	while (!scanf_s("%f", &n))
	{
		printf("Введённый символ не является числом. Повторите ввод ещё раз, please: \n");
		rewind(stdin);//Перемещает указатель положения в начало указанного потока
	}
	return n;
}
