#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long int amount(long int number, long int N)
{
	long int kolvo = 0, temp = 0;
	for (int a1 = 0; a1 < 10; a1++) {
	  for (int a2 = 0; a2 < 10; a2++) {
	    for (int a3 = 0; a3 < 10; a3++) {
	       for (int a4 = 0; a4 < 10; a4++) {
		  for (int a5 = 0; a5 < 10; a5++) {
		     for (int a6 = 0; a6 < 10; a6++) {
			for (int a7 = 0; a7 < 10; a7++) {
			    for (int a8 = 0; a8 < 10; a8++)
				{
				  temp++;
				  int sum = 0;
				  if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0 && a7 == 0)sum = 0;
				  else if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0)sum = abs(a8 * 9 - a7 * 9);
				  else if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0)sum = abs(a8 * 99 - a6 * 99);
				  else if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0)sum = abs(a8 * 999 + a7 * 90 - a6 * 90 - a5 * 999);
				  else if (a1 == 0 && a2 == 0 && a3 == 0)sum = abs(a8 * 9999 + a7 * 990 - a5 * 990 - a4 * 9999);
				  else if (a1 == 0 && a2 == 0)sum = abs(a8 * 99999 + a7 * 9990 + a6 * 900 - a5 * 900 - a4 * 9990 - a3 * 99999);
				  else if (a1 == 0)sum = abs(a8 * 999999 + a7 * 99990 + a6 * 9900 - a4 * 9900 - a3 * 99990 - a2 * 999999);
				  else sum = abs(a8 * 9999999 + a7 * 999990 + a6 * 99900 + a5 * 9000 - a4 * 9000 - a3 * 99900 - a2 * 999990 - a1 * 9999999);
				  if (sum <= N){kolvo++;
				}
			     if (temp > number)return kolvo;
				                             }
			                              }
						}
					}
				}
			}
		}
		
	}

	return kolvo;
}


int perevorot(int x) {
	int s = 0;
	while (x)
		{
			s = s * 10 + x % 10;
			x = x / 10;
	}
	return(s);
}



int main()
{
	long int firstnumber, secondnumber, N;
	scanf("%ld %ld %ld", &firstnumber, &secondnumber, &N);
	clock_t time;
	time= clock();
	if (secondnumber==100000000 && 99999999<=N)printf("\n%ld", (amount(secondnumber, N) - amount(firstnumber-1, N) + 1));
	else printf("\n%ld", amount(secondnumber, N)-amount(firstnumber-1,N));
	time = clock()-time;
	printf("\nIt took me %d clicks (%f seconds).\n", time, ((float)time) / CLOCKS_PER_SEC);
	return 0;
}
