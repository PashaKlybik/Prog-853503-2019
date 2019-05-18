#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>

int main(int argc, const char * argv[]) 
{
	setlocale(LC_ALL, "Russian");
	printf("¬ведите размер пол€ \n");
	int n;
	scanf_s("%d", &n);
	int **a;
	a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	printf("¬ведите матрицу \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (a[i][j] == 1)
				a[i][j] = -1;
			else
				a[i][j] = -2;
		}
	}
	int xn, yn;
	printf("¬ведите координаты старта \n");
	scanf_s("%d", &xn);
	scanf_s("%d", &yn);
	xn--;
	yn--;
	int xk, yk;
	printf("¬ведите координаты финиша\n");
	scanf_s("%d", &xk);
	scanf_s("%d", &yk);
	xk--;
	yk--;
	int stop = 0, d = 0;
	int dx[4] = { 1, 0, -1 , 0 };
	int dy[4] = { 0, 1, 0, -1 };
	a[xn][yn] = 0;
	do 
	{
		d = d + 1;
		stop = 1;
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				if (a[x][y] == d - 1)
					for (int i = 0; i < 4; i++) 
					{
						int xc = x + dx[i];
						int yc = y + dy[i];
						if (xc >= 0 && xc < n && yc >= 0 && yc < n && a[xc][yc] == -2)
							a[xc][yc] = d;
						stop = 0;
					}
	} while (stop == 0 && a[xk][yk] == -2);


	int d1 = 1;
	while (d1 <= d) 
	{
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				if (a[x][y] == d1) 
				{
					for (int i = 0; i < 4; i++) 
					{
						int xc = x + dx[i];
						int yc = y + dy[i];
						int xc1 = xc + dx[i];
						int yc1 = yc + dy[i];
						if (xc >= 0 && xc < n && yc >= 0 && yc < n) 
						{
							if (a[xc][yc] < d1 && a[xc][yc] != -1 && a[xc][yc] != -2) 
							{
								if (xc1 >= 0 && xc1 < n && yc1 >= 0 && yc1 < n) 
								{
									if (a[xc][yc] >= a[xc1][yc1] && a[xc1][yc1] != -1 && a[xc1][yc1] != -2)
										a[x][y] = a[xc][yc];
									else
										a[x][y] = a[xc][yc] + 1;
								}
								else a[x][y] = a[xc][yc] + 1;
							}
						}
					}
				}
		d1++;
	}
	printf("%d\t", a[xk][yk]);
	int time = a[xk][yk];


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == -1) 
			{
				for (int w = 0; w < n; w++)
					for (int q = 0; q < n; q++) 
					{
						if (a[w][q] != -1)
							a[w][q] = -2;
					}
				a[i][j] = -2;
				a[xn][yn] = 0;
				stop = 0;
				d = 0;
				do 
				{
					d = d + 1;
					stop = 1;
					for (int x = 0; x < n; x++)
						for (int y = 0; y < n; y++)
							if (a[x][y] == d - 1)
								for (int i = 0; i < 4; i++) 
								{
									int xc = x + dx[i];
									int yc = y + dy[i];
									if (xc >= 0 && xc < n && yc >= 0 && yc < n && a[xc][yc] == -2)
										a[xc][yc] = d;
									stop = 0;
								}
				} while (stop == 0 && a[xk][yk] == -2);


				int d1 = 1;
				while (d1 <= d) {
					for (int x = 0; x < n; x++)

						for (int y = 0; y < n; y++)
							if (a[x][y] == d1) {
								for (int i = 0; i < 4; i++) 
								{
									int xc = x + dx[i];
									int yc = y + dy[i];
									int xc1 = xc + dx[i];
									int yc1 = yc + dy[i];
									if (xc >= 0 && xc < n && yc >= 0 && yc < n) 
									{
										if (a[xc][yc] < d1 && a[xc][yc] != -1 && a[xc][yc] != -2) 
										{
											if (xc1 >= 0 && xc1 < n && yc1 >= 0 && yc1 < n) 
											{
												if (a[xc][yc] >= a[xc1][yc1] && a[xc1][yc1] != -1 && a[xc1][yc1] != -2)
													a[x][y] = a[xc][yc];
												else
													a[x][y] = a[xc][yc] + 1;
											}
											else a[x][y] = a[xc][yc] + 1;
										}
									}
								}
							}
					d1++;
				}
				if (time > a[xk][yk])
					time = a[xk][yk];
				a[i][j] = -1;
			}
	printf("%d\n", time);
	_getch();
}

