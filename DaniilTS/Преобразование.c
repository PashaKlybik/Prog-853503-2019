#include <tchar.h>
#include <stdio.h>
#include <malloc.h>

int main()
{
	int array_size, *A, *B, i, j, min, sum = 0, reiteration;
	printf("write the size of your array:\n");
	while (1)//����������� ���� ��� �������� ������������ ����� ������� �������
	{
		scanf("%d",&array_size);
		if (array_size <= 0)
		{
			printf("array size cannot be less than or equal to zero");
			continue;
		}
		break;
	}

	A = (int*)malloc(array_size * sizeof(int));//�������� ������� A
	for ( i = 0 ; i < array_size; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &A[i]);//���� ��������� ��� ������� A
	}

	printf("Write the number of reiterations:\n");
	while (1)
	{
		scanf("%d",&reiteration);
		if (reiteration < 0)
		{
			printf("reiteration size cannot be less than zero");
			continue;
		}

		else if (reiteration == 0)
		{
			for (i = 0; i < array_size; i++)
			{
				sum = sum + A[i];//������ �����
			}

			printf("%d",sum);//����� ����������

            system("pause");
			return 0;
		}
		break;
	}
///////////////////////////////������ �����/////////////////////////////////////
	for (j = 0; j < reiteration; j++)
	{
		min = A[0];
		for (i = 0; i < array_size; i++)
		{
			if (A[i] < min)
			{
				min = A[i];//������ ����������� ������� �������
			}
		}

		B = (int*)malloc(array_size * sizeof(int));//�������� ������� B
		for (i = 0; i < array_size; i++)
		{
			B[i] = min - A[i];//���������� �������� ��������� �������
		}

		for (i = 0; i < array_size; i++)
		{
			A[i] = B[i];
		}
	}
///////////////////////////////����� �����//////////////////////////////////////

	for (i = 0; i < array_size; i++)
	{
		sum = sum + B[i];//������ �����
	}

	printf("%d",sum);//����� ����������

////////////////////////////////////////////////////////////////////////////////
	free(A);//���� ������
	free(B);//���� ������
	system("pause");
	return 0;
}
