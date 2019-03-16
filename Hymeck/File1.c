#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <conio.h>
//nclude <stdlib.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int _tmain(int argc, _TCHAR* argv[]) 
{

	int ed, dec, sot;
	int i;
	for (i = 100; i <= 999; i++)
	{
		ed = i% 10;
		dec = (i/10) % 10;
		sot = i/100;
		if (i == ed*ed*ed + dec*dec*dec + sot*sot*sot)
		{
			printf("%d ", i);

		}
	}
	getch();
	return 0;
}
