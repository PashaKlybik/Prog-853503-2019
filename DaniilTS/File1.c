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
	if (k%2==0)//нахождение цифр, которые €вл€ютс€ единицами
	{
		a=k/2;
		a=a+10;
		a=a%10;//нахожу остаток от делени€, тоесть цифры, которые €вл€ютс€ единицами
		printf("%d",a);//вывод цифр €вл€ющихс€ единицами
	}
	else//нахождение цифр, которые €вл€ютс€ дес€тками
	{
		k=k+1;//делаю нецелое число целым
		a=k/2;
		a=a+10;
		a=a/10;//нахожу частное, тоесть цифры, которые €вл€ютс€ дес€тками
		printf("%d",a);//¬ывод чисел €вл€ющихс€ дес€тками
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int k;
	while (1)
	{
		printf("Vvedite k-uy cifru, chto vi hotite naity:");
		scanf("%d",&k);
		if (k>=1&&k<=196)
		{
			search(k);//функци€ поиска и вывода  -той цифры из последовательности
			break;
		}
	}
	getch();
	return 0;
}
