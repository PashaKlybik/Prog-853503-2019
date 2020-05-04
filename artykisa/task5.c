
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<malloc.h>
int main()
{
	int x1, y1, x2, y2, px, py, pr;
	scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
	scanf_s("%d%d%d", &px, &py, &pr);
	int der = abs((x2 - x1+1)*(y2 - y1+1));
	printf("\n%d\n", der);
	for (int i = x1; i <= x2; i++) {
		for (int j =y1; j <= y2; j++) {
			if (sqrt(powl((i - px), 2) + powl((j - py), 2)) <= pr) {
				der--;
			}
		}
		
	}
	printf("\n%d", der);
}
