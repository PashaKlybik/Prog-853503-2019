#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include "time.h"
#include <string.h>
#include "stdlib.h"
#include"conio.h"

typedef struct
{
	double sortTime; // ����� �������������
	char sortName[20];
	long int number_of_permutations;
}sortType;

int defineRandom()
{
	int value;
	while (scanf_s("%d", &value) != 1 || getchar() != '\n' || value < 1)
	{
		printf("Wrong input! Enter again (value > 0!): ");
		rewind(stdin);
	}
	return value;
}

void swap(int *a, int *b, sortType *Sort)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	Sort->number_of_permutations++;
}

int getMenuChoice()
{
	char choice;
	int value;

	if (!(choice = _getch()))
		choice = _getch();

	if (choice >= '0' && choice <= '9')
	{
		value = atoi(&choice);
		return value;
	}
	else return -1;
}

int getArraySize()
{
	int value;
	while (scanf_s("%d", &value) != 1 || getchar() != '\n' || value < 2)
	{
		printf("Wrong input! Enter again (size > 2!): ");
		rewind(stdin);
	}
	return value;
}

void arraycpy(int *arr, int *arrSource, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = arrSource[i];
	}
}

int fillArray(int *arr, int size, int border)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (border + 1);
	}
	return 1;
}


sortType QuickSort;
//������� ����������
void quickSort(int *arr, int size, int left, int right)
{
	int i = left;
	int j = right;
	int test = arr[(left + right) / 2];
	do
	{
		while (arr[i] < test)i++;
		while (arr[j] > test)j--;
		if (i <= j)
		{
			swap(&arr[i++], &arr[j--], &QuickSort);
		}

	} while (i <= j);
	if (i < right)
		quickSort(arr, size, i, right);
	if (j > left)
		quickSort(arr, size, left, j);

}
//����������� ����������
sortType BubbleSort;
void bubbleSort(int* arr, int size)
{
	int i, j;
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1], &BubbleSort);
			}
		}
	}
}
// ���������� ��������( �����������)
sortType ShakerSort;
void shakerSort(int *arr, int start, int size)
{
	int Left, Right, i;
	Left = start;
	Right = size - 1;
	while (Left <= Right)
	{
		for (i = Right; i >= Left; i--)
			if (arr[i - 1] > arr[i]) swap(&arr[i], &arr[i - 1], &ShakerSort);
		Left++;
		for (i = Left; i <= Right; i++)
			if (arr[i] > arr[i + 1]) swap(&arr[i], &arr[i - 1], &ShakerSort);
		Right--;
	}
}
sortType ShellSort;
// ���������� �����
void shellSort(int *arr, int size)
{
	int change = 1;
	int gap = size;
	while (change || gap > 1)
	{
		gap = gap / 1.27;
		gap < 1 ? gap = 1 : gap += 0;
		change = 0;
		for (int i = 0; i < size - gap; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				swap(&arr[i], &arr[i + gap], &ShellSort);
				change = 1;
			}
		}
	}
}
sortType InsertSort;
// ���������� ���������
void insertSort(int *arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i;
		while (arr[j] < arr[j - 1] && j>0)
		{
			swap(&arr[j], &arr[j - 1], &InsertSort);
			j--;
		}
	}
}

// ������� "�����������" ����� ���� - ������������ ����
void siftDown(int *arr, int root, int bottom)
{
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
	// ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // ���� �� � ��������� ����,
			maxChild = root * 2;    // ���������� ����� �������
			 // ����� ���������� ������� ������� �� ����
		else if (arr[root * 2] > arr[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// ���� ������� ������� ������ ������������� �������
		if (arr[root] < arr[maxChild])
		{
			int temp = arr[root]; // ������ �� �������
			arr[root] = arr[maxChild];
			arr[maxChild] = temp;
			root = maxChild;
		}
		else // �����
			done = 1; // �������� ������������
	}
}
sortType HeapSort;
// ������� ���������� �� ����
void heapSort(int *arr, int size)
{
	// ��������� ������ ��� ��������
	for (int i = (size / 2) - 1; i >= 0; i--)
		siftDown(arr, i, size - 1);
	// ���������� ����� �������� ��������� ��������
	for (int i = size - 1; i >= 1; i--)
	{
		swap(&arr[0], &arr[i], &HeapSort);
		siftDown(arr, 0, i - 1);
	}
}
sortType MergeSort;
// ������� ���������� ����������� ��������
void mergeSort(int *arr, int n)
{
	int mid = n / 2; // ������� �������� ����������� ������������������
	if (n % 2 == 1)
		mid++;
	int h = 1; // ���
	// �������� ������ ��� ����������� ������������������
	int *c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   // ������ ������� ����
		int j = mid; // ������ ������� ����
		int k = 0;   // ������ �������� � �������������� ������������������
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ // ���� �� ����� �� ����� ����
			 // ��������� ��������� ������� ����������� ������������������
			 // ������� �� ���� ���������������
				if (arr[i] < arr[j])
				{
					c[k] = arr[i];
					i++; k++;
				}
				else {
					c[k] = arr[j];
					j++; k++;
				}
			}
			while (i < step)
			{ // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
				c[k] = arr[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j < n))
			{  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
				c[k] = arr[j];
				j++; k++;
			}
			step = step + h; // ��������� � ���������� �����
		}
		h = h * 2;
		// ��������� ������������� ������������������ (������������� �������) � �������� ������
		for (i = 0; i < n; i++)
			arr[i] = c[i];
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*��� ������� ����������*/
double getFuncTime(void function(int*, int, int, int), int *arr, int size, int left, int right)
{
	clock_t start_1 = clock();
	function(arr, size, left, right);
	clock_t stop_1 = clock();
	return (double)(stop_1 - start_1) / CLOCKS_PER_SEC;
}
/*��� ����������� , ���������� , ��������� � ����� */
double getFuncTime(void function(int*, int), int *arr, int size)
{
	clock_t start_1 = clock();
	function(arr, size);
	clock_t stop_1 = clock();
	return (double)(stop_1 - start_1) / CLOCKS_PER_SEC;
}
/*��� ���������� ��������*/
double getFuncTime(void function(int*, int, int), int *arr, int start, int size)
{
	clock_t start_1 = clock();
	function(arr, start, size);
	clock_t stop_1 = clock();
	return (double)(stop_1 - start_1) / CLOCKS_PER_SEC;
}
/* ��� */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

FILE *fileDATA;
void printResult(sortType Sort, int mode)
{
	fileDATA = fopen("DATA", "a+b");
	fseek(fileDATA, 0, SEEK_SET);
	if (mode)
	{
		printf(" _________________ SORTING CONTEST ____________________\n");
		printf("________________________________________________________________\n");
		printf(" ||    Sorting name    ||   Time   ||  Permutations  ||\n");
		printf(" ||____________________||__________||________________||\n");
	}
	while (1)
	{
		fread(&QuickSort, sizeof(QuickSort), 1, fileDATA);
		fread(&ShakerSort, sizeof(ShakerSort), 1, fileDATA);
		fread(&BubbleSort, sizeof(BubbleSort), 1, fileDATA);
		fread(&ShellSort, sizeof(ShellSort), 1, fileDATA);
		fread(&InsertSort, sizeof(InsertSort), 1, fileDATA);
		fread(&HeapSort, sizeof(HeapSort), 1, fileDATA);
		fread(&MergeSort, sizeof(MergeSort), 1, fileDATA);
		if (feof(fileDATA)) {
			printf(" ||____________________||__________||________________||\n");
			break;
		}
		printf(" ||____________________||__________||________________||\n");
		printf(" ||%-20s||%-10.5lf||%-16ld||\n", Sort.sortName, Sort.sortTime, Sort.number_of_permutations);
	}
	fclose(fileDATA);
}

void showContestResults()
{
	printResult(QuickSort, 1);
	printResult(ShakerSort, 0);
	printResult(BubbleSort, 0);
	printResult(ShellSort, 0);
	printResult(InsertSort, 0);
	printResult(HeapSort, 0);
	printResult(MergeSort, 0);
}


void startContest(int *Array, int *ArrayTest, int size)
{
	//������� ����������
	arraycpy(Array, ArrayTest, size);
	fileDATA = fopen("DATA", "a+b");
	QuickSort.sortTime = getFuncTime(quickSort, Array, size, 0, size - 1);
	strcpy(QuickSort.sortName, "Quick sort");

	//���������� ��������
	arraycpy(Array, ArrayTest, size);
	ShakerSort.sortTime = getFuncTime(shakerSort, Array, 1, size);
	strcpy(ShakerSort.sortName, "Shaker Sort");

	//����������� ����������
	arraycpy(Array, ArrayTest, size);
	BubbleSort.sortTime = getFuncTime(bubbleSort, Array, size);
	strcpy(BubbleSort.sortName, "Bubble Sort");

	//���������� �����
	arraycpy(Array, ArrayTest, size);
	ShellSort.sortTime = getFuncTime(shellSort, Array, size);
	strcpy(ShellSort.sortName, "Shell Sort");

	//���������� ���������
	arraycpy(Array, ArrayTest, size);
	InsertSort.sortTime = getFuncTime(insertSort, Array, size);
	strcpy(InsertSort.sortName, "Insert Sort");

	//���������� �����
	arraycpy(Array, ArrayTest, size);
	HeapSort.sortTime = getFuncTime(heapSort, Array, size);
	strcpy(HeapSort.sortName, "Heap Sort");

	//���������� ��������
	arraycpy(Array, ArrayTest, size);
	MergeSort.sortTime = getFuncTime(mergeSort, Array, size);
	strcpy(MergeSort.sortName, "Merge Sort");

	fwrite(&QuickSort, sizeof(QuickSort), 1, fileDATA);// ������ � ����
	fwrite(&ShakerSort, sizeof(ShakerSort), 1, fileDATA);
	fwrite(&BubbleSort, sizeof(BubbleSort), 1, fileDATA);
	fwrite(&ShellSort, sizeof(ShellSort), 1, fileDATA);
	fwrite(&InsertSort, sizeof(InsertSort), 1, fileDATA);
	fwrite(&HeapSort, sizeof(HeapSort), 1, fileDATA);
	fwrite(&MergeSort, sizeof(MergeSort), 1, fileDATA);
	fclose(fileDATA);
}

void showWinnerANDLoser()
{
	sortType sorts[7];
	sorts[0] = QuickSort;
	sorts[1] = ShakerSort;
	sorts[2] = BubbleSort;
	sorts[3] = ShellSort;
	sorts[4] = InsertSort;
	sorts[5] = HeapSort;
	sorts[6] = MergeSort;
	sortType winnerTime = sorts[0], winnerPermutations = sorts[0];
	sortType loserTime = sorts[0], loserPermutations = sorts[0];

	for (int i = 1; i < 7; i++)
	{
		if (sorts[i].sortTime < winnerTime.sortTime)
			winnerTime = sorts[i];

		if (sorts[i].number_of_permutations < winnerPermutations.number_of_permutations)
			winnerPermutations = sorts[i];

		if (sorts[i].sortTime > loserTime.sortTime)
			loserTime = sorts[i];

		if (sorts[i].number_of_permutations > loserPermutations.number_of_permutations)
			loserPermutations = sorts[i];
	}
	printf(" ____________________________   WINNERS & LOSERS   _____________________________\n");
	printf("________________________________________________________________________________\n");
	printf(" ||      Nomination       ||        Name        ||   Time   ||  Permutations  ||\n");
	printf(" ||_______________________||____________________||__________||________________||\n");

	printf(" ||      Best of time     ||%-20s||%-10.5lf||%-16ld||\n", winnerTime.sortName, winnerTime.sortTime, winnerTime.number_of_permutations);
	printf(" ||_______________________||____________________||__________||________________||\n");
	printf(" || Best of permutations  ||%-20s||%-10.5lf||%-16ld||\n", winnerPermutations.sortName, winnerPermutations.sortTime,
		winnerPermutations.number_of_permutations);
	printf(" ||_______________________||____________________||__________||________________||\n");
	printf(" ||     Worst of time     ||%-20s||%-10.5lf||%-16ld||\n", loserTime.sortName, loserTime.sortTime, loserTime.number_of_permutations);
	printf(" ||_______________________||____________________||__________||________________||\n");
	printf(" || Worst of permutations ||%-20s||%-10.5lf||%-16ld||\n", loserPermutations.sortName, loserPermutations.sortTime,
		loserPermutations.number_of_permutations);
	printf(" ||_______________________||____________________||__________||________________||\n");
	system("pause");
	system("cls");
}