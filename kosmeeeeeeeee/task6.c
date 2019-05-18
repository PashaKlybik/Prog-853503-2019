#include <stdio.h>
#include <malloc.h>
#include <conio.h>

const int QMAX = 20000000;
int amm = 0;
int min = 99999,min2 = 99999;


struct coord
{
	int x;
	int y;
	int x_from;
	int y_from;
	int turn;
	int wall;
};
struct queue
{
	coord qu[QMAX];
	int frnt, rear;

};
void init(struct queue *q) {
	q->frnt = 1;
	q->rear = 0;
	return;
}
void insert(struct queue *q, coord xy) {
	if (q->rear < QMAX - 1) {
		q->rear++;
		q->qu[q->rear] = xy;
	}
	else
		printf("q is full!\n");
	return;
}
int isempty(struct queue *q) {
	if (q->rear < q->frnt)    return(1);
	else  return(0);
}
coord remove(struct queue *q) {
	coord xy;
	xy.x = -1;
	xy.y = -1;
	if (isempty(q) == 1) {
		printf("q is empty!\n");
		return(xy);
	}
	xy = q->qu[q->frnt];
	q->frnt++;
	return(xy);
}



int **arr;
int N;


int main()
{
	queue *q = new queue;
	init(q);
	int x1,y1,x2,y2;
	
	scanf("%d", &N);
	 arr = (int**)malloc((N+2) * sizeof(int));
	for (int i = 0; i < N+2; i++)
		arr[i] = (int*)malloc((N+2) * sizeof(int));
	for (int i = 0; i < N+2; i++)
	{
		arr[0][i] = 2;
		arr[i][0] = 2;
		arr[N + 1][i] = 2;
		arr[i][N + 1] = 2;

	}

	for (int i = 1; i <= N; i++)
	{
		
		for (int j = 1; j <= N; j++)
		{
			int c = _getch()-48;		
			if (c == 1 || c == 0)
			{
				arr[i][j] = c;
				printf("%d ", arr[i][j]);
			}
			else
				j--; 
		}
		printf("\n");
	}
	scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
	
	
	

	if (arr[x1 + 1][y1] != 2)
	{
		
		coord temp;
		if (arr[x1 + 1][y1] == 1)
		{
			temp.wall = 1;
		}
		else temp.wall = 0;
		temp.x = x1 + 1;
		temp.y = y1;
		temp.x_from = x1;
		temp.y_from = y1;
		temp.turn = 1;
		insert(q, temp);

	}
	if (arr[x1 - 1][y1] !=2)
	{
		coord temp;
		if (arr[x1 - 1][y1] == 1)
		{
			temp.wall = 1;
		}
		else temp.wall = 0;
		temp.x = x1 - 1;
		temp.y = y1;
		temp.x_from = x1;
		temp.y_from = y1;
		temp.turn = 1;
		insert(q, temp);

	}
	if (arr[x1][y1+1] !=2)
	{
		coord temp;
		if (arr[x1][y1+1] == 1)
		{
			temp.wall = 1;
		}
		else temp.wall = 0;
		temp.x = x1;
		temp.y = y1+1;
		temp.x_from = x1;
		temp.y_from = y1;
		temp.turn = 1;
		insert(q, temp);

	}
	if (arr[x1][y1-1] !=2)
	{
		coord temp;
		if (arr[x1][y1-1] == 1)
		{
			temp.wall = 1;
		}
		else temp.wall = 0;
		temp.x = x1;
		temp.y = y1 - 1;
		temp.x_from = x1;
		temp.y_from = y1;
		temp.turn = 1;
		insert(q, temp);

	}

	while (amm<(N*N)&&isempty(q)!=1&& q->rear < QMAX - 1)
	{
		coord temp = remove(q);
		int x1 = temp.x;
		int y1 = temp.y;

		if (x1 == x2 && y1 == y2)
		{
			if (temp.wall == 0)
			{
				amm++;

				if (min > temp.turn)
				{
					min = temp.turn;

				}
				if (min2 > min)
					min2 = min;
			}
			if (temp.wall == 1)
			{
				amm++;
				if (min2 > temp.turn)
				{
					min2 = temp.turn;
				}
			}
		}

		if (arr[x1][y1 + 1] != 2&&temp.y_from!=(y1+1))
		{
			coord tmp;
			if (arr[x1][y1 + 1] == 1)
			{
				tmp.wall = temp.wall+1;
			}
			else tmp.wall = temp.wall;
			tmp.x = x1;
			tmp.y = y1 + 1;
			tmp.x_from = x1;
			tmp.y_from = y1;
			if (tmp.x == temp.x&&tmp.x == temp.x_from)
			{
				tmp.turn = temp.turn;

			}
			else
			{
				tmp.turn = temp.turn + 1;
			}
			insert(q, tmp);

		}
		if (arr[x1][y1 - 1] != 2 && temp.y_from != (y1 - 1))
		{
			coord tmp;
			if (arr[x1][y1 - 1] == 1)
			{
				tmp.wall = temp.wall + 1;
			}
			else tmp.wall = temp.wall;
			tmp.x = x1;
			tmp.y = y1 - 1;
			tmp.x_from = x1;
			tmp.y_from = y1;
			if (tmp.x == temp.x&&tmp.x == temp.x_from)
			{
				tmp.turn = temp.turn;

			}
			else
			{
				tmp.turn = temp.turn + 1;
			}
			insert(q, tmp);

		}
		if (arr[x1+1][y1] != 2 && temp.x_from != (x1 + 1))
		{
			coord tmp;
			if (arr[x1+1][y1] == 1)
			{
				tmp.wall = temp.wall + 1;
			}
			else tmp.wall = temp.wall;
			tmp.x = x1+1;
			tmp.y = y1;
			tmp.x_from = x1;
			tmp.y_from = y1;
			if (tmp.y == temp.y&&tmp.y == temp.y_from)
			{
				tmp.turn = temp.turn;

			}
			else
			{
				tmp.turn = temp.turn + 1;
			}
			insert(q, tmp);

		}
		if (arr[x1 - 1][y1] != 2 && temp.x_from != (x1 - 1))
		{
			coord tmp;
			if (arr[x1-1][y1] == 1)
			{
				tmp.wall = temp.wall + 1;
			}
			else tmp.wall = temp.wall;
			tmp.x = x1 - 1;
			tmp.y = y1;
			tmp.x_from = x1;
			tmp.y_from = y1;
			if (tmp.y == temp.y&&tmp.y == temp.y_from)
			{
				tmp.turn = temp.turn;

			}
			else
			{
				tmp.turn = temp.turn + 1;
			}
			insert(q, tmp);

		}


	}
	printf("%d %d", min,min2);
}
