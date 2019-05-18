#include <stdio.h>
#include <cstdlib>

bool checkProfit(int s,int f, int k) 
{
	int x1=0,x2=s;
	while(s)
	{
		x1 += s % 10;
		s /= 10;
		x1 *= 10;
	}
	x1 /= 10;
	printf("%d %d\n", x1, x2);
	if (abs(x2 - x1) <= k) { return true; }
}

int main()
{
	int s, f, k, amt = 0;
	
	scanf_s("%d%d%d", &s, &f, &k);
	for (; s <= f; s++)
	{
		if(checkProfit(s, f, k) == true)  amt++;
	}
	
printf_s("%d", amt);
}
