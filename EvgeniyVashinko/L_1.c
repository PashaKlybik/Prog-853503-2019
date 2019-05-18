
// --------------------- Lab_1 Variant_5 ------------------------------
#include <stdio.h>

int main()
{
	int n;
	printf("Enter number ");
	scanf("%d", &n); // Ввод n
	printf("increase: ");
	int i;
	for (i = 12; i <= n; i++) // Перебираем числа от 12 до n
	{
		int num = i;
		while (num)
		{
			int a = num;
			int b = num % 10;
			num /= 10;
			int c = num % 10;
			if (c >= b) break; // Если цифры идут не по возрастанию, выходим из цикла
			if (c < b && a < 10) {
				printf("%d", i);
				printf(" ");
			}
		}
	}
	printf("\n\ndecrease: ");
	for (i = 10; i <= n; i++) // Перебираем числа от 10 до n
	{
		int num = i;
		while (num)
		{
			int a = num;
			int b = num % 10;
			num /= 10;
			int c = num % 10;
			if (c <= b) break; // Если цифры идут не по убыванию, выходим из цикла
			if (c > b && num < 10) {
				printf("%d", i);
				printf(" ");
			}
		}
	}
	return 0;
}
