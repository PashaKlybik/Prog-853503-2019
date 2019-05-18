#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
	int counter = 0,length;
	char str[30],first_leter;
	cout<<"Write your string: ";
	gets(str);
	length = strlen(str);
	first_leter = str[0];
	for (int i = 0; i < length; i++)
	{
		if (str[i]=='b'&&str[i+1]=='b')
		{
			cout<<"b";
			continue;
		}
		else if (str[i]==first_leter)
		{
			counter++;
			if (str[i+1]!=first_leter)
			{
				if (counter == 1)
				{
					cout << first_leter;
				}
				else
				{
					cout << counter << first_leter;
				}
				counter = 0;
				first_leter = str[i+1];
			}
		}
	}
	getch();
	return 0;
}
