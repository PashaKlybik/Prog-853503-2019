#include <stdio.h>
#include <conio.h>

int main()
{
	int weight=0, dist=0,trucks;
	while (true)
	{
		printf("1 - Make order\n2 - Show info about my order\n3 - About\n4 - Exit\n");
		int c = _getch()-48;
		if (c > 0 && c < 5)
		{
			switch (c)
			{
			case 1:
				
				while (true)
				{
					printf("input weight of load in t: ");
					scanf_s("%d", &weight);
					if (weight < 20 || weight > 300)
					{
						printf("wrong input\n");
						continue;
					}
					printf("input distance in km: ");
					scanf_s("%d", &dist);
					if (dist > 4000)
					{
						printf("wrong input\n");
						continue;
					}
					printf("ur order succesfully accepted\n");
					break;
					
				}
				break;
			case 2:
				if (!weight && !dist)
				{
					printf("u have no order\n");
					
				}
				else
				{
					trucks = (weight + 19) / 20;
					printf("needed amount of trucks: %d\n", trucks);
					printf("price for ur order with insurance: %d$\n", int(trucks*dist * 2 * 1.05));
					printf("price for insurance %d$\n", int(trucks*dist * 2 * 0.05));
					
				}
				break;
			case 3:printf("Version: 1.0.0\n Author: Artur Matsuk\n");
				break;
			case 4: return 0;
			}
		}
   }
}
