#include <stdio.h>
#include <stdlib.h>


int main()
{
	char S[1000001];
	int repetition = 1;
	int len = 0;
	char ch;
	printf_s("%s", "Enter string:\n");
	scanf_s("%c", &ch);
	while (ch != '\n')			
	{
		S[len] = ch;
		len++;
		scanf_s("%c", &ch);
	}
	S[len] = ch;
	printf_s("%s", "Answer:\n");
	if (len == 1)
		printf_s("%c", S[0]);				
	else
	{
		if (S[0] != S[1])
			printf_s("%c", S[0]);			
		for (int i = 1; i <= len; i++)
			if (S[i] == S[i - 1])		
				repetition++;				
			else
			{
				if (repetition > 2)			
					printf_s("%d", repetition);
				else
					if (repetition == 2)	
						printf_s("%c", S[i - 2]);
				repetition = 1;			
				printf_s("%c", S[i - 1]);	
			}
	}
	getch();
}