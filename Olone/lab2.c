//12 var, 853503, Tikhanovich Dmitry
/*To develop a program, with a menu that allows you to input the coordinates of the vertices of the triangle, 
to determine the shape of a triangle, output the perimeter, area, radius of inscribed and circumscribed circles, 
and also the version and the author of the program */

#include "pch.h"
#include <stdio.h>
#include <math.h>

int ax, bx, cx, ay, by, cy;
long double a, b, c, P, S;
long double vpiscircle = 2 * S / P, opiscircle = a * b*c / (4 * S);

void input()
{
	printf("input coordinates of 3 points\n");
	scanf_s("%d", &ax);
	scanf_s("%d", &ay);
	scanf_s("%d", &bx);
	scanf_s("%d", &by);
	scanf_s("%d", &cx);
	scanf_s("%d", &cy);
	c = powl(pow(ax - bx, 2) + pow(ay - by, 2), 0.5);
	b = powl(pow(ax - cx, 2) + pow(ay - cy, 2), 0.5);
	a = powl(pow(cx - bx, 2) + pow(cy - by, 2), 0.5);
}

void vid()
{
	bool priznak = false;
	if (a == b && b == c)
	{
		printf("equilaterial\n");
		priznak = true;
	}
	else {
		if (a == b || a == c || b == c)
		{
			printf("isosceles\n");
			priznak = true;
		}
	}
	if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(c, 2) + pow(b, 2) == pow(a, 2))
	{
		printf("recangular\n");
		priznak = true;
	}
	if (priznak == false)
	{
		printf("versatile\n");
	}
}

long double perimetr()
{
	return a + b + c;
}

long double area()
{
	P = perimetr();
	return powl(P / 2 * (P / 2 - a)*(P / 2 - b)*(P / 2 - c), 0.5);
}

void circles()
{
	S = area();
	vpiscircle = 2 * S / P;
	printf("%f - inscribed\n", vpiscircle);
	opiscircle = a * b * c / (4 * S);
	printf("%f - outscribed\n", opiscircle);
}

int main()
{
	int l = 1;
	input();
	while (l != 0)
	{
		printf("1 - input\n2 - type\n3 - perimeter\n4 - area\n5 - radius of inscribed and outscribed circles\n6 - info about version and author0 - exit\n");
		scanf_s("%d", &l);
		if (l == 1)
		{
			input();
		}
		if (l == 2)
		{
			vid();
		}
		if (l == 3)
		{
			printf("");
			printf("%f\n", perimetr());
		}
		if (l == 4)
		{
			printf("");
			printf("%f\n", area());
		}
		if (l == 5)
		{
			circles();
		}
		if (l == 6)
		{
			printf("version 1.0.1\nauthor Tikhanovich Dmitry\n");
		}
	}
}

