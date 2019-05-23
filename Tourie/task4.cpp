#include <iostream>
#include <cmath>
using namespace std;

int reverse(int number);

int main()
{
	int S, F, K;
	cout << "S: ";
	cin >> S;
	cout << "F: ";
	cin >> F;
	cout << "K: ";
	cin >> K;
	cout << endl;
	int count = 0;
	while (S <= F)
	{
		if (abs(S - reverse(S)) <= K)
		{
			count++;
		}
		S++;
	}
	cout << count;
}

int reverse(int number)
{
	int res = 0;
	while (number != 0)
	{
		res = res * 10 + number % 10;
		number /= 10;
	}
	return res;
}

