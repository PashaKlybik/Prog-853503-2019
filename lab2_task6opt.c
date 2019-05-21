#include <stdio.h>

int matrica(int x1, int y1, int x2, int y2, int** matrix, int n)
	// функция для подсчета количества шагов(алгоритм волновой трассировки)
{
	int stop = 0, d = 0;
	int dx[4] = {1, 0, -1, 0
	}; // создаем вспомогательные массивы для расстановки шагов
	int dy[4] = {0, 1, 0, -1};
	matrix[x1][y1] = 0;

	do {
		d++;
		stop = 1;
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)

				if (matrix[x][y] == d - 1)
					for (int i = 0; i < 4; i++) {
						int xc = x + dx[i];
						int yc = y + dy[i];
						if (xc >= 0 && xc < n && yc >= 0 && yc <
							n && matrix[xc][yc] == -2)
							matrix[xc][yc] = d;
						stop = 0;
					}

	}
	while (stop == 0 && matrix[x2][y2] == -2);
	// расстановка значений для определения шагов

	int d1 = 1;
	while (d1 <= d) // определение количества шагов
	{
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				if (matrix[x][y] == d1) {
					for (int i = 0; i < 4; i++) {
						int xc = x + dx[i];
						int yc = y + dy[i];
						int xc1 = xc + dx[i];
						int yc1 = yc + dy[i];
						if (xc >= 0 && xc < n && yc >= 0 && yc < n) {
							if (matrix[xc][yc] <
								d1 && matrix[xc][yc] != -1 && matrix[xc][yc]
								!= -2) {
								if (xc1 >= 0 && xc1 < n && yc1 >= 0 && yc1 < n)
								{
									if (matrix[xc][yc] >=
										matrix[xc1][yc1] && matrix[xc1][yc1]
										!= -1 && matrix[xc1][yc1] != -2)
										matrix[x][y] = matrix[xc][yc];
									else
										matrix[x][y] = matrix[xc][yc] + 1;
								}
								else
									matrix[x][y] = matrix[xc][yc] + 1;
							}
						}
					}
				}
		d1++;
	}
}

int main(int argc, const char * argv[]) {
	printf("Enter matrix size : "); // ввод размера матрицы
	int matrix_size;
	scanf("%d", &matrix_size);

	int **matrix; // выделение памяти под матрицу
	matrix = (int**)malloc(matrix_size*sizeof(int*));
	for (int i = 0; i < matrix_size; i++)
		matrix[i] = (int*)malloc(matrix_size*sizeof(int)); ;
	printf("Enter matrix values\n"); // ввод матрицы
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++) {
			scanf("%d", &matrix[i][j]);
		}
	int x1, y1; // ввод первой координаты
	printf("Input first koordinate \n");
	scanf("%d", &x1);
	scanf("%d", &y1);
	x1--;
	y1--;
	int x2, y2;
	printf("Input second koordinate\n");
	scanf("%d", &x2);
	scanf("%d", &y2);
	x2--;
	y2--;
	int** firstmatrica;
	firstmatrica = (int**)malloc(matrix_size*sizeof(int*));
	// создаем матрицу для подсчета первого значения, используя волновой метод
	for (int i = 0; i < matrix_size; i++)
		firstmatrica[i] = (int*)malloc(matrix_size*sizeof(int)); ;
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++)
			firstmatrica[i][j] = matrix[i][j];
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			if (firstmatrica[i][j] == 1)
				firstmatrica[i][j] = -1;
			else
				firstmatrica[i][j] = -2;
		}
	}
	matrica(x1, y1, x2, y2, firstmatrica, matrix_size);
	// вызов функции для определения количества шагов
	printf("first number = %d\n", firstmatrica[x2][y2]);
	int min_kolvo = firstmatrica[x2][y2];
	for (int i = 0; i < matrix_size; i++)
		free(firstmatrica[i]);
	free(firstmatrica);
	for (int i = 0; i < matrix_size;
	i++) // определение наименьшего количества шагов, если убрать одну фигуру
	{
		for (int j = 0; j < matrix_size; j++) {
			if (matrix[i][j] == 1) { // находим фигуру
				matrix[i][j] = 0; // удаляем ее
				int** secondmatrica;
				secondmatrica = (int**)malloc(matrix_size*sizeof(int*));
				for (int i = 0; i < matrix_size; i++)
					secondmatrica[i] = (int*)malloc(matrix_size*sizeof(int)); ;
				for (int i = 0; i < matrix_size; i++)
					for (int j = 0; j < matrix_size; j++)
						secondmatrica[i][j] = matrix[i][j];
				for (int i = 0; i < matrix_size; i++) {
					for (int j = 0; j < matrix_size; j++) {
						if (secondmatrica[i][j] == 1)
							secondmatrica[i][j] = -1;
						else
							secondmatrica[i][j] = -2;
					}
				}
				matrica(x1, y1, x2, y2, secondmatrica, matrix_size);
				if (secondmatrica[x2][y2] < min_kolvo)
					min_kolvo = secondmatrica[x2][y2];
				// если получается меньшее значение, присваиваем переменной новое значение
				for (int i = 0; i < matrix_size; i++)
					free(secondmatrica[i]); // высвобождаем память
				free(secondmatrica);
				matrix[i][j] = 1;
			}

		}
	}

	printf("second number = %d\n", min_kolvo); // вывод значения
	free(matrix);
	return 0;
}