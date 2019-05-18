#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define sqrt_2 1.4142135623730950488016887242097;
#define sqrt_3 1.7320508075688772935274463415059;
#define sqrt_23 0.81649658092772603273242802490195;

double Perimeter(double const side);
double Surface(double const side);
double Volume(double const side);
double Height(double const side);
double RadiusOfInsertedBall(double const side);

double Perimeter(double const side)
{
	return (side * 6);
}

double Surface(double const side)
{
	return side * side * sqrt_3;
}

double Volume(double const side)
{
	double h = Height(side);
	return h / 3 * side * side * sqrt_3;
}

double Height(double const side)
{
	return side * sqrt_23;
}

double RadiusOfInsertedBall(double const side)
{
	return Height(side)/3;
}

void About()
{
	printf("\n\t Author: Vlad\n\t Version: 1.0");
}

int main()
{

	double side = 0; 
	char tmp = ' ';
	printf("Input side : "); 
	while (!scanf_s("%lf", &side))
	{
		tmp = getchar();
		while (tmp != '\n')
			tmp = getchar();
		system("clear");
		printf("Please, input valid side (number): ");
	}
	double p = Perimeter(side), s = Surface(side), v = Volume(side), h = Height(side), r = RadiusOfInsertedBall(side);
	printf("Side:\t\t\t %lf \nPerimeter:\t\t %lf \nSurface:\t\t %lf \nVolume:\t\t\t %lf\nHeight:\t\t\t %lf \nRadius of Inserted Ball: %lf",side, p,s,v,h,r);
	About();
	return 0;
}