#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void quicksort(int *, int); // сортировка массива
int check(int a); // функция для проверки вводимых значений

int main() {
	int proverka = 0;
	int N, *MyMassive;
	while (!proverka) // ввод количества элементов массива
	{
		printf("Enter the number of elements in the array: ");
		scanf("%d", &N);
		proverka = check(N);
	}
	MyMassive = (int*)malloc(N*sizeof(int));
	printf("Enter array elements: \n"); // ввод элементов массива
	for (int i = 0; i < N; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &MyMassive[i]);
	}
	quicksort(MyMassive, N); // сортировка массива
	int min = MyMassive[0];
	// определение максимального и минимального значений для
	int max = MyMassive[N - 1];
	// их дальнейшего использования в полученных формулах
	int sum = 0;
	for (int i = 0; i < N; i++) // подсчет первичной суммы элементов массива
	{
		sum += MyMassive[i];
	}
	int Repetition;
	printf("Enter the number of repetitions: ");
	scanf_s("%d", &Repetition); // ввод количества операций
	if (Repetition == 0)
		printf("sum = %d", sum);
	else {
		int i = 1;
		do { // вычисления сводятся к полученным формулам
			sum = 5 * min - sum;
			if (i == 1)
				min = min - max;
			i++;
		}
		while (i <= Repetition);

		printf("sum = %d", sum);
	}
	free(MyMassive); // высвобождение памяти
	return 0;
}

void quicksort(int *arr, int size) // сортировка массива
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int check(int a) // проверка на ввод
{
	if (a < 0)
		return 0;
	else
		return 1;
}