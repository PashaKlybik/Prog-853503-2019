#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string>

int main()
{
	int Number, counter = 0;
	char *str;
	char buffer[10];
	cout<<"Write the nuber, please: ";
	cin>>Number;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
		{
			str = itoa(i,buffer,10);
			for (int j = 0; j < strlen(str); j++)
			{
				if (str[j]=='4'||str[j]=='7')
				{
					counter++;
				}
			}
		}
	}
	cout<<counter;
	getch();
	return 0;
}
