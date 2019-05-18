#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int discount(char *price)
{
	for (int i = 0; i < strlen(price)/2; i++)
	{
		char temp = price[i];
		price[i] = price[strlen(price) - 1 - i];
		price[strlen(price) - 1 - i] = temp;
		
	}
	return atoi(price);
}

int main()
{
	int a, b, k,amm=0;
	char price[12];
	scanf_s("%d%d%d", &a,&b,&k);
	for (a; a <= b; a++)
	{
		sprintf_s(price, "%d", a);
		if (abs(discount(price) - a) <= k)
			amm++;
	}
	
	printf_s("%d", amm);
	
	
}

	