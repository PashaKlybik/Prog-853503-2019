#include <stdio.h>
#include <string.h>
#include <cmath>
int numbers(int k)
{
	int res = 0;
	while (k)
	{
		k = k / 10;
		res++;
	}
	return res;
}

int main()
{
	bool flag = 1;
	int cur=0,k=1;
	char str[1000];
	gets_s(str);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == str[i + 1] &&str[i] == str[i + 2])
		{
			for (int j = 1; flag; j++)
			{
				if (str[i] == str[i + j])
					k++;
				else
				{
					flag = 0;
					if (k > 9)
					{
						int temp =numbers(k)-1;
						int n=k;
						char ch = str[i + 1];
						while (temp>=0)
						{
							
							
							str[cur] = n / pow(10, temp)+'0';
								n = n % int(pow(10,temp));
								cur++;
								temp--;
						}
						str[cur] = ch;
					}
					else
					{
						str[cur] = k + '0';
						str[cur + 1] = str[i + 1];
						cur++;
					}
					i += k - 1;
					
					k = 1;
				}
			}
		flag = 1;
		}
		str[cur] = str[i];
		cur++;
	}
	str[cur] = '\0';
	for (int i = 0; i < strlen(str); i++)
	{
		printf_s("%c", str[i]);
	}
}

