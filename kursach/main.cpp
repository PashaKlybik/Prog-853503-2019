#include "Functions.h"


int main()
{

	srand(time(NULL));
	int *Array = NULL, *ArrayTest = NULL;
	int size, extremeValue;
	int menuNum;
	while (1)
	{
		printf("========= CONTEST MENU ==========\n");
		printf("Chose operation:\n");
		printf("1.Array filling\n");
		printf("2.Show contest results\n");
		printf("3.Sort top results\n");
		printf("4.Exit\n");
		menuNum = getMenuChoice();
		switch (menuNum)
		{
		case 1: system("cls");
			remove("DATA");
			QuickSort.number_of_permutations = 0;
			ShakerSort.number_of_permutations = 0;
			BubbleSort.number_of_permutations = 0;
			ShellSort.number_of_permutations = 0;
			InsertSort.number_of_permutations = 0;
			HeapSort.number_of_permutations = 0;
			MergeSort.number_of_permutations = 0;
			printf("Enter size of array (the array will be filled randomly): ");
			size = getArraySize();
			printf("Enter extreme value (extreme value > 0): ");
			extremeValue = defineRandom();
			if (Array && ArrayTest)
			{
				free(Array);
				free(ArrayTest);
				Array = NULL;
				ArrayTest = NULL;
			}
			ArrayTest = (int*)malloc(sizeof(int)*size);
			Array = (int*)malloc(sizeof(int)*size);
			fillArray(ArrayTest, size, extremeValue);
			printf("Please, wait...\n");
			startContest(Array, ArrayTest, size);

			system("cls");
			printf("The array was created successfully!\n\n");
			break;

		case 2: system("cls");
			if (!Array && !ArrayTest)
			{
				printf("You haven't created an array yet!\n\n");
				break;

			}

			showContestResults();
			system("pause");
			system("cls");
			break;

		case 3: system("cls");
			if (!Array && !ArrayTest)
			{
				printf("You haven't created an array yet!\n\n");
				break;
			}
			showWinnerANDLoser();
			break;

		case 4: system("cls");
			return 0;

		default: system("cls");
			printf("Enter correct operation!\n\n");
			break;
		}
	}
}