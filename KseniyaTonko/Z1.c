#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{

	long N, answer = 0;
	printf_s("%s", "Enter N: ");
	scanf_s("%li", &N);
	for (long i = 1; i <= N; i++)			
		if (N % i == 0)											
		{
			long number = i;
			bool isHappy = false;
			while (number > 0)
			{
				if ((number % 10 == 4) || (number % 10 == 7))	
					isHappy = true;
				number = (long)(number / 10);
			}
			if (isHappy)
				answer++;										
		}
	long number = N;
	bool isHappy = false;
	while (number > 0)											
	{
		if ((number % 10 == 4) || (number % 10 == 7))
			isHappy = true;
		number = (long)(number / 10);
	}
	if (isHappy)
		answer++;
	printf_s("%s%li", "Answer: ", answer);
	getch();
}
