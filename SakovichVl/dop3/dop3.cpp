#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
	bool a = true;
	char arr[1000];
	int str[1000][2],amt=0;
	gets_s(arr);
	for (; arr[amt] != '\0'; amt++)
	{
		str[amt][0] = arr[amt];
	}
	for (int i = 0; i < amt-1; i++) 
	{
		if ( str[i][0]==str[i+1][0] && str[i][0]==str[i+2][0]) 
		{
			int amount=2,j=i+2;
			while(str[j][0] == str[i][0])
			{
					j++; amount++;
			}
			str[i][1] = amount;
			str[i][0] = 0;
			for (int m = i + 2; m < amt; m++)
			{
				str[m][0] = str[m + amount - 2][0];
			}
			amt -= amount - 2;
			i += 1;
		}
	}
	for (int i = 0; i < amt ; i++)
	{
		if (str[i][0] == 0) { printf("%d", str[i][1]); }
		else printf("%c", str[i][0]);
	}

}
