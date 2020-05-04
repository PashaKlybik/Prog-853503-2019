
#include<stdbool.h>
#include <stdio.h>
#include<malloc.h>
int main() {
	int *ukaz= (int*)malloc(sizeof(int)), size;
	printf("Enter massiv size\n");
	scanf_s("%d", &size);
	ukaz = (int*)malloc(size * sizeof(int));
	printf("Vvedite elementi massiva\n");
	for (int i = 0; i < size; i++) {
		printf("ukaz[%d] = ", i);
		scanf_s("%d", &ukaz[i]);
	}
	
	int min = ukaz[0];
	for (int i = 1; i < size; i++) {
		if (min > ukaz[i]) min = ukaz[i];
	}
	int* ukaz2= (int*)malloc(sizeof(int));
	int smen;
	printf("Vvedite kol-vo smen\n");
	ukaz2 = (int*)malloc(size * sizeof(int));
	scanf_s("%d", &smen);
	bool kak = 1;
	for (int i = 0; i < smen; i++) {
		
		if (kak == 1) {
			
			ukaz2 = (int*)malloc(sizeof(int));
			ukaz2 = (int*)malloc(size * sizeof(int));
			int min = ukaz[0];
			for (int i = 1; i < size; i++) {
				if (min > ukaz[i]) min = ukaz[i];
			}

			for (int j = 0; j < size; j++) {
				ukaz2[j] = min - ukaz[j];
			}
			kak = 0;
			free(ukaz);
		}
		else {
			
			ukaz= (int*)malloc(sizeof(int));
			ukaz = (int*)malloc(size * sizeof(int));
			int min = ukaz2[0];
			for (int i = 1; i < size; i++) {
				if (min > ukaz2[i]) min = ukaz2[i];
			}

			for (int j = 0; j < size; j++) {
				ukaz[j] = min - ukaz2[j];
			}
			kak = 1;
			free(ukaz2);
		}
	}
	int summa = 0;
	for (int i = 0; i < size; i++) {
		if (kak || smen == 0) {
			printf("%d", ukaz[i]);
			summa += ukaz[i];
		}
		else {
			 printf("%d", ukaz2[i]);
			 summa += ukaz2[i];
		}
		printf(" ");
	}
	printf("Summa massiva= ");
	printf("%d", summa);
	getchar();
	getchar();
	return 0;
}
