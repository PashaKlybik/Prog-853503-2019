#include <iostream>
using namespace std;

int digit(int num)
{
	int j = 0, count = 0;
	int a[100000];
	while (num != 0)
	{
		int r = num % 10;
		num = num / 10;
		a[j] = r;
		j++;
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		if (a[i] == 4 || a[i] == 7)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}

int main()
{
	int N, a = 0;
	cout << "Insert the number:";
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		if (N % i == 0)
		{
			a += digit(i);
		}
	}
	cout << "Number of happy dividers:" << a;

}