#include <tchar.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int start, end, a, b=0, i, first_number, range, price_change, counter = 10;
	while (1)
	{
		printf("strating price:\n");
		scanf("%d",&start);
		if (start<=0)
		{
			system("cls");
			printf("starting price can not be less or equal to zero\n");
			continue;
		}
		printf("ending price:\n");
		scanf("%d",&end);
		if (end<=0)
		{
			system("cls");
			printf("final price can not be less or equal to zero\n");
		}
		if (end < start)
		{
			system("cls");
			printf("final price can not be less than the initial\n");
			continue;
		}
        printf("acceptable price change:");
		scanf("%d",&price_change);
		if (price_change<=0)
		{
			printf("price change can not be less or equal to zero");
			continue;
		}
		break;
	}

	range = end-start;//высчитываю диапазон между начальной ценой и конечной
	first_number = start+1;//нахожу первое число
	for (i = 1; i < range; i++)
	{
		a = first_number;
		while (a!=0)
		{
			b=b*10+a%10;
			a=a/10;
		}

		if ( abs(b - first_number) <= price_change)
		{
			counter++;
		}
		b = 0;
		first_number +=1;
	}

	printf("%d",counter-9);
////////////////////////////////////////////////////////////////////////////////
	system("pause");
	return 0;
}
