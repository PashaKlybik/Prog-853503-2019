#include <stdio.h>
#include "math.h"

int main()
{
	int x1, x2, y1, y2, px, py, pr,amt=0;
	scanf_s("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf_s("%d%d%d", &px, &py, &pr);
	for(;x1<=x2;x1++)
	{
		for (int i=y1; i <= y2; i++) 
		{
			if (sqrt(pow(x1-px,2)+pow(i-py,2))>pr)
			{
				amt++;
			}
		}
	}
	printf("%d", amt);
}
