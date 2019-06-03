#include <stdlib.h>
#include <stdio.h>

int reverse(int);

int main()
{
	int S, F, K, answer = 0;
	printf_s("%s", "Enter S: ");
	scanf_s("%d", &S);
	printf_s("%s", "Enter F: ");
	scanf_s("%d", &F);
	printf_s("%s", "Enter K: ");
	scanf_s("%d", &K);
	for (int i = S; i <= F; i++)
		if (abs(reverse(i) - i) <= K)
			answer++;
	printf_s("%s", "Answer: ");
	printf_s("%d", answer);
	getch();
}

int reverse(int i)
{
	int number = 0;
	while (i > 0)
	{
		number = number * 10 + i % 10;
		i /= 10;
	}
	return number;
}