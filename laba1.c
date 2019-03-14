//Вариант 30
#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <locale.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	int i,k;
	start:system("cls");
	printf("Vvedite k-toe chislo posledovatelnosty, kotoroe vi hotite vivesti.\n");
	scanf("%d",&k);
	if (k<0||k>89)
	{
		goto start;
	}

	system("cls");

	for (i = 0; i < 90; i++)
	{
		if (i==k)
		{
			printf("%d ",i+10);
		}
	}

	system ("pause");
	return 0;
}
