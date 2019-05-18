#include <stdio.h>
#include <math.h>

int ShowHappiness(long int);
_Bool isHappyDivider(int);

int main()
{
	long int n;
	FILE *input = fopen("input.txt", "r");
	fscanf(input, "%li", &n);
	fclose(input);
	FILE * output = fopen("output.txt","w");
	fprintf(output,"%i",ShowHappiness(n));
	fclose(output);
	return 0;
}

int ShowHappiness(long int n)
{
	//printf("dividers\n");
	long int sqrt_num = (int)sqrt((double)n) + 1, count = 0;
	for (long int i = 2; i < sqrt_num; i++) {
		if (n % i == 0 && i != n)
		{
			if (isHappyDivider(i))
				count++;
			if (isHappyDivider(n / i))
				count++;
			if (i == sqrt_num)
				count--;
			// printf("%li\n", i);
			// printf("%li\n", n / i);
		}
	}
	return count;
}

_Bool isHappyDivider(int n)
{
	while (n)
	{
		int tmp = n % 10;
		if (tmp == 4 || tmp == 7)
			return 1;
		n /= 10;
	}
	return 0;
}