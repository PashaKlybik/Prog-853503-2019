//Вариант 30
#include <stdio.h>
#include <conio.h>
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void search(int k)
{
	int a;
	if (k%2==0)//нахождение цифр, которые являются единицами
	{
		a=k/2;
		a=a+10;
		a=a%10;//нахожу остаток от деления, тоесть цифры, которые являются единицами
		printf("%d",a-1);//вывод цифр являющихся единицами
	}
	else//нахождение цифр, которые являются десятками
	{
		k=k+1;//делаю нецелое число целым
		a=k/2;
		a=a+10;
		a=a/10;//нахожу частное, тоесть цифры, которые являются десятками
		printf("%d",a);//Вывод чисел являющихся десятками
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int k;
	while (1)
	{
		printf("Vvedite k-uy cifru, chto vi hotite naity:");
		scanf("%d",&k);
        system("cls");
		if (k>=1&&k<=196)
		{
			search(k);//функция поиска и вывода К-той цифры из последовательности
			break;
		}
	}
	getch();
	return 0;
}
