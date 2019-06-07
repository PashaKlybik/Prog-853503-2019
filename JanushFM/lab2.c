#include <iostream>
#include <math.h>
using namespace std;
bool zadano = false;
bool exist = true;
float AB, BC, AC;
float Ax, Bx, Cx, Ay, By, Cy;
float Radius(bool output);
void EnterCoordinates()
{
	printf("Enter coordinates of triangle:\n");
	printf("Enter Ax:");
	scanf_s("%f", &Ax);
	printf("Enter Bx:");
	scanf_s("%f", &Bx);
	printf("Enter Cx:");
	scanf_s("%f", &Cx);
	printf("Enter Ay:");
	scanf_s("%f", &Ay);
	printf("Enter By:");
	scanf_s("%f", &By);
	printf("Enter Cy:");
	scanf_s("%f", &Cy);

	AB = sqrt(pow((By - Ay), 2) + pow((Bx - Ax), 2));
	BC = sqrt(pow((By - Cy), 2) + pow((Cx - Bx), 2));
	AC = sqrt(pow((Cy - Ay), 2) + pow((Cx - Ax), 2));

	zadano = true;
}
void length()
{
	AB = sqrt(pow((By - Ay), 2) + pow((Bx-Ax), 2));
	BC = sqrt(pow((By - Cy), 2) + pow((Cx - Bx), 2));
	AC = sqrt(pow((Cy - Ay), 2) + pow((Cx - Ax), 2));
}
void type()
{
	if (AB == BC == AC) printf_s("Right triangle");
	else if (AB == BC || AB == AC || BC == AC)
	{
		if(AB== 2.0*Radius(false) || BC == 2.0*Radius(false) || AC ==  2.0*Radius(false) ) printf_s("Rectangular triangle");
		else
		{
			printf_s("Arbitrary triangle");
		}
	}

}
float perimeter(bool output)
{
	float perimeter = AB + BC + AC;
	if(output==true) printf_s("Perimeter:%f", perimeter);
	return perimeter;
}
float area(bool output)
{
	float area;
	area = ((Ax - Cx)*(By - Cy) - ((Bx - Cx)*(Ay - Cy)))/2.0;
	if(output==true)printf_s("Area is:%f", area);
	return area;
}
float Radius(bool output)
{
	float r,R;
	r = sqrt((perimeter(false) / 2.0 - AB)*(perimeter(false) / 2.0 - BC)*(perimeter(false) / 2.0 - AC)/(perimeter(false)/2));
	R = AB * BC*AC / (4 * area(false));
	if (output == true)
	{
		printf_s("Radius of the inscribed circle%f", r);
		printf_s("/nRadius of the circumscribed circle%f", R);
	}
	return R;
}
bool check()
{
	if ((Ax == Bx && Bx == Cx) || (Ay == By && By == Cy)) return false;
	else return true;
}
void version()
{
	printf_s("Version:1.0\nAuthor is Janush Fiaskou\n");
}
int main()
{
	bool condition = true, cond2 = true;
	int choice=0;
	while (condition)
	{
		printf_s("\n1.Enter coordinates\n2.Defining type of rectangle\n3.Perimeter of rectangle\n4.Area of rectangle is:\n5.Radius\n6.Version and authour\n7.Exit\n");
		
		scanf_s("%d", &choice);
		if (choice == 0)
		{
			char f = ' ';
			f = getchar();
			while (f!='\n')
			{
				f = getchar();
			}
			printf_s("Input is incorrect, try again:");
			continue;
		}
		switch (choice)
		{
		case 1:EnterCoordinates();
			break;
		case 2:if (zadano == false) printf("Firstly you must enter coordinates\n");
			   else if (!check()) printf_s("Rectangle isn't exist\n");
				else type();
			break;
		case 3:if (zadano == false) printf("Firstly you must enter coordinates\n");
			   else if (!check()) printf_s("Rectangle isn't exist\n");
			else perimeter(true);
			break;
		case 4:if (zadano == false) printf_s("Firstly you must enter coordinates\n");
			   else if (!check()) printf_s("Rectangle isn't exist\n");
			else area(true);
			break;
		case 5:if (zadano == false) printf("Firstly you must enter coordinates\n");
			   else if (!check()) printf_s("Rectangle isn't exist\n");
			else Radius(true);
			break;
		case 6:if (zadano == false) printf("Firstly you must enter coordinates\n");
			   else if (!check()) printf_s("Rectangle isn't exist\n");
			else version();
			break;
		case 7:condition = false;
			break;
		}
		
	}
	
	system("pause");
	return 0;
}