#include <stdio.h>
#include <stdlib.h>

void DrawMap(int ** map,int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%i ",map[i][j]);
		printf("\n");
	}
}

int FindWave(int startX, int startY, int targetX, int targetY, int N, int ** map)
{
	_Bool add = 1;
	int ** cMap = (int **)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++)
		cMap[i] = (int *)malloc(N*sizeof(int));
	int x, y, step = 0, gap = 0;
	for (y = 0; y < N; y++)
		for (x = 0; x < N; x++)
		{
			if (map[y][x] == 1)
				cMap[y][x] = -2; //wall
			else
				cMap[y][x] = -1; //not stept yet
		}
	cMap[targetY][targetX] = 0; //Начинаем с финиша
	while (add)
	{
		add = 0;
		for (y = 0; y < N; y++)
		{
			for (x = 0; x < N; x++)
			{
				if (cMap[x][y] == step)
				{
					while (cMap[x+gap][y]!=-2)
					{
						if (cMap[x + gap][y] == -1)
							cMap[x + gap][y] = step + 1;
						gap++;
						if (x+gap>=N) break;
					}
					gap = 0;
					while (cMap[x - gap][y]!=-2)
					{
						if (cMap[x - gap][y] == -1)
							cMap[x - gap][y] = step + 1;
						gap++;
						if (x-gap<0) break;
					}
					gap = 0;
					while (cMap[x][y - gap]!=-2)
					{
						if (cMap[x][y - gap] == -1)
							cMap[x][y - gap] = step + 1;
						gap++;
						if (y-gap<0) break;
					}
					gap = 0;
					while (cMap[x][y + gap]!=-2)
					{
						if (cMap[x][y + gap] == -1)
							cMap[x][y + gap] = step + 1;
						gap++;
						if (y+gap>=N) break;
					}
					gap = 0;
				}
			}
		}
		step++;
		add = 1;
		if (cMap[startY][startX] != -1) //решение найдено
			add = 0;
		if (step > N * N) //решение не найдено
			add = 0;
	}
	
	//Отрисовываем карты
	// for (y = 0; y < N; y++)
	// {
	// 	printf("\n");
	// 	for (x = 0; x < N; x++)
	// 		if (cMap[y][x] == -1)
	// 			printf("   ");
	// 		else
	// 		if (cMap[y][x] == -2)
	// 			printf("#  ");
	// 		else
	// 		if (y == startY && x == startX)
	// 			printf("S  ");
	// 		else
	// 		if (y == targetY && x == targetX)
	// 			printf("F  ");
	// 		else
	// 		if (cMap[y][x] > -1)
	// 		{
	// 			if (cMap[y][x] <= 9) printf ("%i  ",cMap[y][x]);
	// 			else if (cMap[y][x] > 9) printf("%i ",cMap[y][x]);
	// 		}
	// }
	return step;
}

int main()
{
	FILE *input;
	input = fopen("input.txt","r");
	int N, timeFirst = 0, timeSecond = 0, stX,stY,endX,endY;
	fscanf(input,"%i",&N);
	int ** cells = (int **)malloc(N*sizeof(int*));
	for (int i = 0; i < N; i++)
		cells[i] = (int *)malloc(N*sizeof(int));
	for (int j = 0; j < N; j++)
		for (int  i = 0; i < N; i++)
			fscanf(input,"%i",&cells[j][i]);
	fscanf(input,"%i%i%i%i",&stY,&stX,&endY,&endX);
	DrawMap(cells,N);
	printf("\n");
	timeFirst = timeSecond = FindWave(stX - 1, stY - 1, endX - 1, endY - 1, N, cells);

	for (int i = 0; i < N; i++)
	{
		for (int  j = 0; j < N; j++)
		{
			if(cells[i][j] == 1)
			{
				cells[i][j] = 0;
				int k =  FindWave(stX - 1, stY - 1, endX - 1, endY - 1, N, cells);
				if (k < timeSecond)
					timeSecond = k;
				cells[i][j] = 1;
			}
		}
		
	}
	FILE * output = fopen("output.txt","w");
	fprintf(output,"%i %i",timeFirst, timeSecond);
	fclose(output);
	fclose(input);
	return 0;
}