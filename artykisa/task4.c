
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int S, F, K;
	printf("Vvedite 3 chisla\n");
	scanf_s("%d%d%d", &S, &F, &K);	
	int schet=0;
	int dlina;
	char itochar[12];
	for (S; S <= F; S++) {
		sprintf_s(itochar, "%d", S);
		char temp;
		for (int i = 0; i < strlen(itochar) / 2; i++)
		{
			temp = itochar[i];
			itochar[i] = itochar[strlen(itochar) - 1 - i];
			itochar[strlen(itochar) - 1 - i] = temp;			
		}
		if (abs(atoi(itochar) - S) <= K) {
			schet++;
		}
	}
	printf("Kol-vo takix chisel=%d",schet);
	return 0;
}
  


