#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	long N, answer = 0;
	printf_s("%s", "Enter N: ");
	scanf_s("%li", &N);
	for (long i = 1; i <= N; i++)			
		if (N % i == 0)											//ïðîâåðêà, ÿâëÿåòñÿ ëè ÷èñëî äåëèòåëåì N
		{
			long number = i;
			bool isHappy = false;
			while (number > 0)
			{
				if ((number % 10 == 4) || (number % 10 == 7))	//ïîèñê öèôð, êîòîðûå äîëæíû áûòü â ïî÷òè ñ÷àñòëèâîì ÷èñëå 
					isHappy = true;
				number = (long)(number / 10);
			}
			if (isHappy)
				answer++;										//åñëè ÷èñëî ïî÷òè ñ÷àñòëèå, óâåëè÷èâàåì îòâåò íà 1
		}
	long number = N;
	bool isHappy = false;
	while (number > 0)											//ïðîâåðêà, ÿâëÿåòñÿ ëè ÷èñëî N ïî÷òè ñ÷àñòëèâûì
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
