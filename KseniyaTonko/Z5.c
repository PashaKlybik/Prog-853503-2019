#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	long X1, Y1, X2, Y2, Px, Py, Pr, answer = 0;
	printf_s("%s", "Enter X1: ");
	scanf_s("%d", &X1);
	printf_s("%s", "Enter Y1: ");
	scanf_s("%d", &Y1);
	printf_s("%s", "Enter X2: ");
	scanf_s("%d", &X2);
	printf_s("%s", "Enter Y2: ");
	scanf_s("%d", &Y2);
	printf_s("%s", "Enter Px: ");
	scanf_s("%d", &Px);
	printf_s("%s", "Enter Py: ");
	scanf_s("%d", &Py);
	printf_s("%s", "Enter Pr: ");
	scanf_s("%d", &Pr);
	for (long i = max(Py - Pr, Y1); i <= min(Py + Pr, Y2); i++)
	{
		double distance = sqrt(pow(Pr, 2) - pow(Py - i, 2));
		answer += min(min(Pr, X2 - Px), (long)distance);			
		answer += min(min(Pr, Px - X1), (long)distance) + 1;		
	}

	printf_s("%s", "\nAnswer: ");
	printf_s("%d", (X2 - X1 + 1)*(Y2 - Y1 + 1) - answer);		
	getch();
}