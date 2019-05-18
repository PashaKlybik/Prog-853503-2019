/*
11. ����������� �����. ����������� ���������, ���� ������� ��������� ��������� ��������� �������:
� ���� ������������ �����.
� ����� ������������ ����� � �������������� �����.
� ����� ������������ ����� � ������������� �����.
� ��������� ������������ ������������ �����.
� ���������� ������������ ����� � ����� ������������� �������.
� ���������� � ������ � ������ ���������.
� ����� �� ���������.
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
	int choice = 1; // ��� ���������� ������� (0 � ����� �� �����, 1 � ���� � ���, 2 � ���� ������ �� �������)
	int real = 0, imaginary = 0; // �������������� � ������ ����� �����
	int check = 0; // ��� �������� �����
	do
	{
		system("cls");
		printf_s("������� �������������� ����� �����: ");
		check = scanf_s("%d", &real);
		if (check != 0)
		{
			printf_s("������� ������ ����� �����: ");
			check = scanf_s("%d", &imaginary);
		}
		if (check == 0)						// �������� �����
		{									//
			printf_s("�������� ����!");		//
			int temp_char = '\0';			//
			scanf_s("%c", &temp_char);		//
			_getch();						//
		}									//
		choice = 1;
		while (choice == 1)
		{
			system("cls");
			printf("1. ����� � �������������� �����\n2. ����� � ������������� �����\n3. ���������� � �������\n"
				"4. ��������� �����������\n5. ���� ������\n6. �����");
			char temp = '\0';
			switch (_getch(temp)) // ����� ������ ����
			{
				case '1': // ����� � ���. �����
				{
					system("cls");
					printf_s("����� � �������������� �����: %d ", real);
					imaginary >= 0 ? printf_s("+ %di", imaginary) : printf_s("- %di", -imaginary); // ����� � ������ �����
					_getch();
					break;
				}
				case '2': // ����� � �����. ����� � ������ ������������ �������� (����)
				{
					system("cls");
					int absolute = sqrt(real * real + imaginary * imaginary); // ���������� ������
					double argument = ToExponential(real, imaginary); // ���������� ���������
					printf_s("����� � ������������� �����: %d * e ^ (%fi)", absolute, argument);
					_getch();
					break;
				}
				case '3': // ���������� ����� ������������� �������
				{
					// ������� ������: x = |x| ^ n * (cos(n * a) + sin(n * a) * i)
					system("cls");
					unsigned int grade = 0;
					double absolute = sqrt(real * real + imaginary * imaginary), // ���������� ������
						argument = ToExponential(real, imaginary); // ���������� ��������� 
					printf_s("������� �������: ");
					scanf_s("%d", &grade);
					double temp_real = pow(absolute, grade) * cos(grade * argument); // �������������� ����� ������ ����� 
					double temp_imaginary = pow(absolute, grade) * sin(grade * argument); // ������
					printf_s("����� � ������� %d: %f ", grade, temp_real);
					temp_imaginary >= 0 ? printf_s("+ %fi", temp_imaginary) : printf_s("- %fi", -temp_imaginary); // ����� � ������ �����
					_getch();
					break;
				}
				case '4': // ������ ����� ����������� �����
				{
					system("cls");
					printf_s("����������: %d ", real);
					imaginary >= 0 ? printf_s("- %di", imaginary) : printf_s("+ %di", -imaginary); // ����� � ������ �����
					_getch();
					break;
				}
				case '5': { choice = 2; break; } // (��������� ���������� ���� � ��������� � �������) ���� ������ �����
				case '6': { choice = 0; break; } // ������� �� ����� ������ (����������)
			}
		}

	} while (choice == 1 || choice == 2);
	return 0;
}

double ToExponential(double real, double imaginary)
{
	if (real > 0)
		return atan(imaginary / real);			// ���������� ���������
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
������ 0.0.0.0.0.1
������� �.�.
*/