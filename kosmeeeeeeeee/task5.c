#include <stdio.h>
#include "math.h"

int main()
{
	bool flag = 0;
	int x1, y1, x2, y2, x, y, r,amm=0;
	scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
	scanf_s("%d%d%d", &x, &y, &r);

	for (int i = y1; i <= y2; i++)
	{
		flag = 0;
		for (int j = x1; j <= x2; j++)
		{
			if (sqrt((i - y)*(i - y) + (j - x)*(j - x)) <= r)
			{
				flag = 1;
			}
			else
			{
				if (flag == 1)
				{
					amm++;
					break;
				}
				else 
				{
					amm++;
				}
					
			}
		}
	}
	printf_s("%d", amm);

}

