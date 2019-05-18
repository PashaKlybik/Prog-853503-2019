/*Рациональные числа. Разработать программу, меню которой
позволяет выполнить следующие функции:
• Ввод (числитель и знаменатель) двух рациональных чисел.
• Вывод двух рациональных чисел (в форме: n/m).
• Сложение чисел.
• Вычитание чисел.
• Умножение чисел.
• Деление чисел.
• Получение гармонического значения двух чисел.
• Информация о версии и авторе программы.
• Выход из программы.

Справка: Гармоническое значение двух чисел получается путем
получения обратных
значений двух чисел, усреднения их и получения обратного
значения результата. */


#include <iostream>
#include <math.h>
#include <string>
#include <locale.h>
#include <Windows.h>

using namespace std;

class Rational
{
public:
	Rational(int a, int b);
	~Rational();
	int m, n;

	void Print(const char name[])
	{
		printf("%s = %d/%d \n", name, m, n);

	}

	Rational Plus(Rational a)
	{
		int u, v;
		u = m * a.n + n * a.m;
		v = n * a.n;
		return (Rational(u, v));
	}

	Rational Minus(Rational a)
	{
		int u, v;
		u = m * a.n - n * a.m;
		v = n * a.n;
		return (Rational(u, v));
	}

	Rational Mult(Rational a)
	{
		int u, v;
		u = m * a.m;
		v = n * a.n;
		return (Rational(u, v));
	}

	Rational Divide(Rational a)
	{
		int u, v;

		u = m * a.n;
		v = n * a.m;
		return (Rational(u, v));

	}

	Rational HarmonicMeaning(Rational a)
	{
		//обмен значений переменных местами
		m = m ^ n;
		n = m ^ n;
		m = m ^ n;

		//обмен значений переменных местами
		a.m = a.m ^ a.n;
		a.n = a.m ^ a.n;
		a.m = a.m ^ a.n;

		int u, v;
		u = m * a.n + n * a.m;
		v = (n * a.n) / 2;

		return (Rational(v, u));
	}


private:
	//функция для нахождения нод двух чисел
	int Nod(int m, int n)
	{
		int p = 0;
		m = abs(m);
		n = abs(n);
		if (n > m)
		{
			p = m;
			m = n;
			n = p;
		}
		do
		{
			p = m % n;
			m = n;
			n = p;
		} while (n != 0);
		return (m);
	}

};

Rational::Rational(int a, int b)
{
	if (b == 0)
	{
		m = 0;
		n = 1;
	}
	else
	{
		if (b < 0) { b = -b; a = -a; }
		int d = Nod(a, b);
		m = a / d;
		n = b / d;
	}
}

Rational::~Rational()
{
}
//Перегрезка оператора +
Rational operator +(Rational r1, Rational r2)
{
	return (r1.Plus(r2));
}

//Перегрезка оператора -
Rational operator -(Rational r1, Rational r2)
{
	return (r1.Minus(r2));
}

//Перегрезка оператора *
Rational operator *(Rational r1, Rational r2)
{
	return (r1.Mult(r2));
}

//Перегрезка оператора /
Rational operator /(Rational r1, Rational r2)
{
	return (r1.Divide(r2));
}

//Перегрезка оператора ==
bool operator ==(Rational r1, Rational r2)
{
	return ((r1.m == r2.m) && (r1.n == r2.n));
}

//Перегрезка оператора !=
bool operator !=(Rational r1, Rational r2)
{
	return ((r1.m != r2.m) || (r1.n != r2.n));
}

//Перегрезка оператора <
bool operator <(Rational r1, Rational r2)
{
	return (r1.m * r2.n < r2.m * r1.n);
}

//Перегрезка оператора >
bool operator >(Rational r1, Rational r2)
{
	return (r1.m * r2.n > r2.m * r1.n);
}

//Перегрезка оператора <
bool operator <(Rational r1, double r2)
{
	return ((double)r1.m / (double)r1.n < r2);
}

//Перегрезка оператора >
bool operator >(Rational r1, double r2)
{
	return ((double)r1.m / (double)r1.n > r2);
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
	gets_s(array);

	for (int i = 0; i < ArrayLenght(array); i++)
	{
		if ((array[0] == '0') || (!isdigit(array[i])))
		{
			printf("The number is entered incorrectly, repeat input.\n");
			return InputCheck();
		}
	}
	return atoi(array);
}
//функция для выбора действия с дробями
int menu() {
	int fractions_operations;

	printf("Enter:\n");
	printf("1-to create one fraction and display them\n");
	printf("2-to create two fractions and their addition\n");
	printf("3-to create two fractionsand subtract them\n");
	printf("4-to create two fractions and multiply them \n");
	printf("5-to create two fractions and their division\n");
	printf("6-to create two fractions and compare them\n");
	printf("7-to create two fractions and get harmonic meaning\n");

	fractions_operations = InputCheck();
	return fractions_operations;
}

//функция для создания двух дробей и их вывода
void TestCreate()
{
	printf("Input numerator ");
	int m1 = InputCheck();
	printf("Input denominator ");
	int n1 = InputCheck();
	Rational r1 = Rational(m1, n1);
	r1.Print("fraction");
}

//функция для создания двух дробей и их сложения
void TestAddition()
{
	printf("Input numerator ");
	int m1 = InputCheck();
	printf("Input denominator ");
	int n1 = InputCheck();
	Rational r1 = Rational(m1, n1);
	printf("Input numerator ");
	int m2 = InputCheck();
	printf("Input denominator ");
	int n2 = InputCheck();
	Rational r2 = Rational(m2, n2);
	r1.Print("r1");
	r2.Print("r2");
	//Rational r3 = r1.Plus(r2);
	Rational r3 = r1 + r2;
	r3.Print("sum");
}

//функция для создания двух дробей и их вычитания
void TestSubtract()
{
	cout << "Input numerator ";
	int m1 = InputCheck();
	printf("Input denominator ");
	int n1 = InputCheck();
	Rational r1 = Rational(m1, n1);
	printf("Input numerator ");
	int m2 = InputCheck();
	printf("Input denominator ");
	int n2 = InputCheck();
	Rational r2 = Rational(m2, n2);
	r1.Print("r1");
	r2.Print("r2");
	//Rational r3 = r1.Minus(r2);
	Rational r3 = r1 - r2;
	r3.Print("min");
}

//функция для создания двух дробей и их перемножения
void TestMultiply()
{
	printf("Input numerator ");
	int m1 = InputCheck();
	printf("Input denominator ");
	int n1 = InputCheck();
	Rational r1 = Rational(m1, n1);
	printf("Input numerator ");
	int m2 = InputCheck();
	printf("Input denominator ");
	int n2 = InputCheck();
	Rational r2 = Rational(m2, n2);
	r1.Print("r1");
	r2.Print("r2");
	//Rational r3 = r1.Mult(r2);
	Rational r3 = r1 * r2;
	r3.Print("mul");
}

//функция для создания двух дробей и их деления
void TestDivision()
{
	printf("Input numerator ");
	int m1 = InputCheck();
	printf("Input denominator ");
	int n1 = InputCheck();
	Rational r1 = Rational(m1, n1);
	printf("Input numerator ");
	int m2 = InputCheck();
	printf("Input denominator ");
	int n2 = InputCheck();
	Rational r2 = Rational(m2, n2);
	r1.Print("r1");
	r2.Print("r2");
	//Rational r3 = r1.Divide(r2);
	Rational r3 = r1 / r2;
	r3.Print("div");
}

//функция для создания двух дробей и их сравниения
void TestCompare()
{
	printf("Input numerator ");
	int m1 = InputCheck();
	printf("Input denominator ");
	int n1 = InputCheck();
	Rational r1 = Rational(m1, n1);
	printf("Input numerator ");
	int m2 = InputCheck();
	printf("Input denominator ");
	int n2 = InputCheck();
	Rational r2 = Rational(m2, n2);
	r1.Print("r1");
	r2.Print("r2");
	if (r1 == r2)
	{
		printf("r1==r2\n");
	}
	else if (r1 > r2)
	{
		printf("r1 > r2\n");
	}
	else if (r1 < r2)
	{
		printf("r1 < r2\n");
	}
}

//функция для создания двух дробей и нахождения их гарманического значения
void TestHarmonicMeaning()
{
	printf("Input numerator ");
	int m1 = InputCheck();
	printf("Input denominator ");
	int n1 = InputCheck();
	Rational r1 = Rational(m1, n1);
	printf("Input numerator ");
	int m2 = InputCheck();
	printf("Input denominator ");
	int n2 = InputCheck();
	Rational r2 = Rational(m2, n2);
	r1.Print("r1");
	r2.Print("r2");
	Rational r3 = r1.HarmonicMeaning(r2);
	r3.Print("harmonic meaning");
}
int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	int counter;
	while (true) {
		printf("Enter:\n");
		printf("1 - for working with fractions \n");
		printf("2 - to receive data about the program\n");
		printf("3 - to exit \n");
		counter = InputCheck();
		switch (counter) {
		case 1:
			switch (menu()) {
			case 1:
				system("cls");
				TestCreate();
				break;
			case 2:
				system("cls");
				TestAddition();
				break;
			case 3:
				system("cls");
				TestSubtract();
				break;
			case 4:
				system("cls");
				TestMultiply();
				break;
			case 5:
				system("cls");
				TestDivision();
				break;
			case 6:
				system("cls");
				TestCompare();
				break;
			case 7:
				system("cls");
				TestHarmonicMeaning();
				break;
			default:
				system("cls");
				printf("Wrong choice/n");
			}
			break;
		case 2:
			system("cls");
			printf("program for working with rational numbers\n");
			printf("author Kiril Rylkov \n");
			break;
		case 3:
			return 0;
		default:
			printf("Wrong choice\n");
		}
	}
}

