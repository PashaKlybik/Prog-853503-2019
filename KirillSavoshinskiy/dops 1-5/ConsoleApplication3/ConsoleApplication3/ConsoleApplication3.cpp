﻿ 

#include <iostream>
#include <string>
using namespace std;

string arch(string str);
string number(int count);

int main()
{
	string str;
	cout << "Enter your string:";
	cin >> str;
	cout << arch(str);
}

string arch(string str)
{
	string res;
	char symbol = str[0];
	int count = 0;
	for (int i = 0; i < str.length() + 1; i++)
	{
		if (str[i] == symbol)
		{
			count++;
		}
		else
		{
			if (count > 2)
			{
				res += number(count);
				res += symbol;
			}
			else if (count == 2)
			{
				res += symbol;
				res += symbol;
			}
			else if (count == 1)
			{
				res += symbol;
			}
			count = 0;
			if (symbol != str[i])
			{
				count = 1;
				symbol = str[i];
			}
		}
	}
	return res;
}

string number(int count)
{
	string num;
	while (count != 0)
	{
		num = '0' + count % 10;
		count /= 10;
	}
	return num;
}
 
