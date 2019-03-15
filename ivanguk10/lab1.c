#include "pch.h"
#include <stdio.h>
#include <math.h>


int main()
{
	double ch;
	int r, k;
	printf("Vvedite chislo:\n");
	scanf_s("%lf", &ch);
	r = ch;
	k = round(100 * (ch - r));
	printf("%d rublei\t%d copeek", r, k);
}