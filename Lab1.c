#include <stdio.h>

//протип фунции
int check(int);

int main()
{
	int start_value = 0, value, buffer;//buffer -- временная переменная
	printf("Input number from 100 to 9999: ");
	start_value = check(start_value);//Проверяем введённое с клавиатуры числo
	if (start_value < 1000)//случай, если число трёхзначное
	{
		value = 1;
		while (start_value > 0)//условие выхода
		{
			buffer = start_value % 10;
			start_value /= 10;
			value *= buffer;
		}
	} 
	else //случай, если число четырёхзначное
	{
		value = 0;
		while (start_value > 0)//условие выхода
		{
			buffer = start_value % 10;
			start_value /= 10;
			value += buffer;
		}
	}
	printf("value= %d", value);
	return 0;
}

// тело функции
int check(int n)
{
	while (!scanf_s("%d", &n) || (n < 100 || n>9999))
	{
		printf("Inccorect value. Try again pls: \n");
		rewind(stdin);
	}
	return n;
}
