

#pragma once
#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159;

struct Points
{
	int x1, y1, x2, y2;
	Points() { x1 = y1 = x2 = y2 = 0; }
};

void InputPoints(Points *p)
{	
	for (int j = 0; j < 3; j++)
	{
		printf("%i vertex:\n", j + 1);
		int numArr[4];
		for (int i = 0; i < 4;)
		{
			
			char symbol = 'x';
			int index = i + 1; // index for changing '*' of x* and y*
			switch (i)
			{
			case 1: symbol++; index = i; break;
			case 2: index = i; break;
			case 3: symbol++; index = i - 1; break;
			default:
				break;
			}
			cout << symbol << index << " = "; // x* или y*, где * - 1 либо 2
			float fVar;
			cin >> fVar;
			if (!cin)
			{
				cout << "Illegal input expression. Try again:\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				numArr[i] = (int)fVar;

				if (numArr[i] != fVar) //проверка введенного числа на наличие дробной части
				{
					cout << "Input integer number\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					i--;
				}
				
				else if (i == 3) // в конецк цикла присваивание 
				{
					p[j].x1 = numArr[0]; p[j].y1 = numArr[1];
					p[j].x2 = numArr[2]; p[j].y2 = numArr[3];
				}
				else 
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				i++;
			}
		}
	}
}

// возвращает растояние 
float CountSide(Points p)
{
	return
		sqrtf(powf((float)(p.x1 - p.x2), 2) + powf((float)(p.y1 - p.y2), 2));
}

bool TriangleExists(Points *p)
{
	int i, j;
	// проверка на то, можно ли через введенные координаты провести прямую 
	for (i = 0; i < 3; i++)
		if (p[i].x1 == p[i].x2 && p[i].y1 == p[i].y2)
			return 0;

	// проверка на наличие эквивалентных отрезков
	for (i = 0; i < 2; i++)
		for (j = i + 1; j < 3; j++)
			if (p[i].x1 == p[j].x1 && p[i].x2 == p[j].x2 &&
				p[i].y1 == p[j].y1 && p[i].y2 == p[j].y2)
				return 0;

	// рассчет расстояния между координатами
	float rA = CountSide(p[0]),
		rB = CountSide(p[1]),
		rC = CountSide(p[2]);

	// не больше ли одна сторона суммы двух других
	if (rA >= rB + rC || rB >= rA + rC || rC >= rA + rB)
		return 0;

	else return 1;
}

int Angle(float r1, float r2, float r3)
{
	return
		(int)(acos((powf(r1, 2) + powf(r2, 2) - powf(r3, 2)) / (2 * r1*r2))*(180 / pi));
}

int TriangleType(Points *p)
{
	// 1 - equilateral, 2 - right-angled, 3 - isosceles, 4 - arbitrary
	int type = 4;
	double pi = 3.14159;
	float rA = CountSide(p[0]),
		rB = CountSide(p[1]),
		rC = CountSide(p[2]);

	int a1 = Angle(rA, rB, rC),
		a2 = Angle(rA, rC, rB),
		a3 = Angle(rC, rB, rA);
	if (a1 == a2 && a2 == a3)
		type = 1;
	else if (a1 == 90 || a2 == 90 || a3 == 90)
		type = 2;
	else if (a1 == a2 || a1 == a2 || a2 == a3)
		type = 3;

	return type;
}



float Perimetre(Points *p)
{
	float rA = CountSide(p[0]),
		rB = CountSide(p[1]),
		rC = CountSide(p[2]); 
	return rA + rB + rC;
}

float Square(Points *p)
{
	float rA = CountSide(p[0]),
		rB = CountSide(p[1]),
		rC = CountSide(p[2]);

	float halfP = (rA + rB + rC) / 2;
	// формула Герона для рассчета площади треугольника
	return sqrtf(halfP * (halfP - rA) * (halfP - rB) * (halfP - rC));
}

void FinalOutput(Points *points, int choice)
{
	switch (choice)
	{
	case 1:  InputPoints(points); break;
	case 2:
		if (points[0].x1 == points[0].x2 && !points[0].x1)
			cout << "Do correct input\n";
		else
		{
			cout << "Triangle ";
			if (TriangleExists(points))
				cout << "exists\n";
			else cout << "does not exist\n";
		}
		break;
	case 3:
		if (!TriangleExists(points))
			cout << "Do correct input\n";
		else
		{
			switch (TriangleType(points))
			{
			case 1: printf("Equilateral triangle\n"); break;
			case 2: printf("Right-angled triangle\n"); break;
			case 3: printf("Isosceles triangle\n"); break;
			case 4: printf("Arbitrary triangle\n"); break;
			default: printf("Something goes wrong\n"); return;
			}
		}
		break;
	case 4:
		if (!TriangleExists(points))
			cout << "Do correct input\n";
		else
			cout << "Perimetre is " << Perimetre(points) << endl;
		break;
	case 5:
		if (!TriangleExists(points))
			cout << "Do correct input\n";
		else
			cout << "Square is " << Square(points) << endl;
		break;
	case 6:
		printf("\n***************************************************");
		printf("\n\nVersion 1.0; Yaroslav Morkhat. All rights reserved.\n\n");
		printf("***************************************************\n");
		break;
	case 7: return;
	default: 
		cout << "Invalid input. Try again\n";
		break;
	}
}