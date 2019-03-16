// L#1_Var#17
#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <conio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void FunctionPrint()
{
	int ed, dec, sot; // объявление переменных для записи цифр единицы, десятка и сотни чисел из заданного промежутка
	int i;
	for (i = 100; i <= 999; i++)
	{
		ed = i% 10; // формула рассчета цифры единицы
		dec = (i/10) % 10; // формула рассчета цифры десятка 
		sot = i/100; // формула рассчета цифры сотни
		if (i == ed*ed*ed + dec*dec*dec + sot*sot*sot) // условие задания: если сумма кубов цифр числа равна числу, то выводим через пробел это число.
		// и так от 100 до 999 ищем
		{
			printf("%d ", i);

		}
	}		
}

int _tmain(int argc, _TCHAR* argv[]) 
{
	FunctionPrint();
	getch();
	return 0;
}
