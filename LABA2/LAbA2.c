//�����������. ����������� ���������, ���� �������? ��������� ��������� ��������� �������
//� ���� ��������� ������ ������������
//� ���������� ��� ������������ (����������?, �������������?,��������������?, ������������� ����).
//� ����� ��������� ������������
//� ����� ������� ������������.
//� ��������� � ������� ������� ���������? � ���������? ������ ������������ �����������?.
//� ��������� � visual studio, ������  ����������, 853503, ������� 12

#include <stdio.h>
#include <math.h> 
#include <locale.h>

double check(float);

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice = 0;
	double  x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, Half_meter = 0, Perimetr = 0, side_one = 0, side_two = 0, side_three = 0, Area = 0, small_radius = 0, big_radius = 0;
	printf("������� ���������� ������ �����: \n");
	x1 = check(x1);
	y1 = check(y1);
	printf("������� ���������� ������ �����: \n");
	x2 = check(x2);
	y2 = check(y2);
	printf("������� ���������� ������ �����: \n");
	x3 = check(x3);
	y3 = check(y3);
	side_one = sqrt(abs(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
	side_two = sqrt(abs(pow((x3 - x2), 2) + pow((y3 - y2), 2)));
	side_three = sqrt(abs(pow((x3 - x1), 2) + pow((y3 - y1), 2)));
	printf("������ ������� = %f\n", side_one);
	printf("������ ������� = %f\n", side_two);
	printf("������ ������� = %f\n", side_three);
	do
	{
		printf("���������� ��� ������������ -- 1\n������� �������� ������������ -- 2\n������� ������� ������������ -- 3\n������� �������� �������� ������������ -- 4\n������� ���������� �� ������ ��������� -- 5\n��������� ������� -- 9\n");
		choice = check(choice);
		system("cls");
		if (choice == 1)
		{
			if (side_one == side_two || side_one == side_three || side_two == side_three)
			{
				printf("����������� �������� ��������������\n");
			}
			if (side_one == side_two && side_two == side_three)
			{
				printf("����������� �������� ����������\n");
			}
			if (pow(side_one, 2) + pow(side_two, 2) == pow(side_three, 2) || pow(side_one, 2) + pow(side_three, 2) == pow(side_two, 2) || pow(side_three, 2) + pow(side_two, 2) == pow(side_one, 2))
			{
				printf("����������� �������� �������������\n");
			}
			else
			{
				printf("����������� �������� ������������\n");
			}
		}
		if (choice == 2)
		{
			Perimetr = side_one + side_two + side_three;
			printf("�������� = %f\n", Perimetr);
		}
		if (choice == 3)
		{
			Half_meter = Perimetr / 2;
			Area = sqrt(Half_meter * (Half_meter - side_one) * (Half_meter - side_two) * (Half_meter - side_three));//������� ������� �� ������� ������
			printf("������� = %f\n", Area);
		}
		if (choice == 4)
		{
			small_radius = (2 * Area) / (side_one + side_two + side_three);
			printf("������ ��������� ���������� = %f\n", small_radius);
			big_radius = (side_one * side_two * side_three) / (4 * Area);
			printf("������ ��������� ���������� = %f\n", big_radius);
		}
		if (choice == 5)
		{
			printf("����� ��������� -- ������ ���������� ����������, ������� 3 ���� 2000 ����, ����� ������� �����������, ����� � ����� �� ��� �������\n");
		}
	}while (choice != 9);

	return 0;
}

double check(float n)
{
	while (!scanf_s("%f", &n))
	{
		printf("�������� ������ �� �������� ������. ��������� ���� ��� ���, please: \n");
		rewind(stdin);//���������� ��������� ��������� � ������ ���������� ������
	}
	return n;
}