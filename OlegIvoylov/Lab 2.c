/*
11. Комплексное число. Разработать программу, меню которой позволяет выполнить следующие функции:
• Ввод комплексного числа.
• Вывод комплексного числа в алгебраической форме.
• Вывод комплексного числа в показательной форме.
• Получение сопряженного комплексного числа.
• Возведение комплексного числа в целую положительную степень.
• Информация о версии и авторе программы.
• Выход из программы.
*/

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double ToExponential(double, double);

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 1; // для управления циклами (0 — выход из обоих, 1 — вход в оба, 2 — вход только во внешний)
	int real = 0, imaginary = 0; // действительная и мнимая части числа
	int check = 0; // для проверки ввода
	do
	{
		system("cls");
		printf_s("Введите действительную часть числа: ");
		check = scanf_s("%d", &real);
		if (check != 0)
		{
			printf_s("Введите мнимую часть числа: ");
			check = scanf_s("%d", &imaginary);
		}
		if (check == 0)						// проверка ввода
		{									//
			printf_s("Неверный ввод!");		//
			int temp_char = '\0';			//
			scanf_s("%c", &temp_char);		//
			_getch();						//
		}									//
		choice = 1;
		while (choice == 1)
		{
			system("cls");
			printf("1. Вывод в алгебраической форме\n2. Вывод в показательной форме\n3. Возведение в степень\n"
				"4. Получение сопряжённого\n5. Ввод заново\n6. Выход");
			char temp = '\0';
			switch (_getch(temp)) // выбор пункта меню
			{
				case '1': // вывод в алг. форме
				{
					system("cls");
					printf_s("Число в алгебраической форме: %d ", real);
					imaginary >= 0 ? printf_s("+ %di", imaginary) : printf_s("- %di", -imaginary); // вывод с учётом знака
					_getch();
					break;
				}
				case '2': // вывод в показ. форме с учОтом координатной четверти (угла)
				{
					system("cls");
					int absolute = sqrt(real * real + imaginary * imaginary); // вычисление модуля
					double argument = ToExponential(real, imaginary); // вычисление аргумента
					printf_s("Число в показательной форме: %d * e ^ (%fi)", absolute, argument);
					_getch();
					break;
				}
				case '3': // вычисление целой положительной степени
				{
					// формула Муавра: x = |x| ^ n * (cos(n * a) + sin(n * a) * i)
					system("cls");
					unsigned int grade = 0;
					double absolute = sqrt(real * real + imaginary * imaginary), // вычисление модуля
						argument = ToExponential(real, imaginary); // вычисление аргумента 
					printf_s("Введите степень: ");
					scanf_s("%d", &grade);
					double temp_real = pow(absolute, grade) * cos(grade * argument); // действительная часть нового числа 
					double temp_imaginary = pow(absolute, grade) * sin(grade * argument); // мнимая
					printf_s("Число в степени %d: %f ", grade, temp_real);
					temp_imaginary >= 0 ? printf_s("+ %fi", temp_imaginary) : printf_s("- %fi", -temp_imaginary); // вывод с учётом знака
					_getch();
					break;
				}
				case '4': // просто вывод сопряжённого числа
				{
					system("cls");
					printf_s("Сопряжённое: %d ", real);
					imaginary >= 0 ? printf_s("- %di", imaginary) : printf_s("+ %di", -imaginary); // вывод с учётом знака
					_getch();
					break;
				}
				case '5': { choice = 2; break; } // (прерывает внутренний цикл и переходит в внешний) ввод нового числа
				case '6': { choice = 0; break; } // выходит из обоих циклов (завершение)
			}
		}

	} while (choice == 1 || choice == 2);
	return 0;
}

double ToExponential(double real, double imaginary)
{
	if (real > 0)
		return atan(imaginary / real);			// вычисление аргумента
	else if (real < 0 && imaginary >= 0)		//
		return M_PI + atan(imaginary / real);	//
	else if (real < 0 && imaginary < 0)			//
		return atan(imaginary / real) - M_PI;	//
	else if (real == 0 && imaginary < 0)		//
		return atan(asin(-1));					//
	else if (real == 0 && imaginary >= 0)		//
		return atan(asin(1));					//
}

/*
Версия 0.0.0.0.0.1
Ивойлов О.А.
*/