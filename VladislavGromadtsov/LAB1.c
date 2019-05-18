//---------Lab1_Var8--------
#include <conio.h>
#include <stdio.h>

int main()
{
	int a,b;
	char s;

	for (;;)
	{
	  printf("Input your num:  ");
	  scanf("%d",&a);                      //Ввод числа

		if (a>999 && a<10000)    //Проверка на 4-х значность
		{
			b = a%100*100;
			a = (a/100) + b;
			printf("Your num :  %d",a);
			printf("\n\n-----------\nExit: press q\nTry again: any another key\n");

		 scanf("%s",&s);
		 if (s=='q') break;  //Проверка на условие выхода из программы
		 system ("cls");

		}else
		{
			 printf("Smth is wrong!Try again!");
			 getch();
			 system ("cls");
		}
	}
	return 0;
}
