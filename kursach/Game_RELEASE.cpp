#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "game.h"
using namespace std;

void game_release::setup()
{
	srand(time(0));
	game_over = false;
	CU = STOP;
	coord.x = width / 2;
	coord.y = height / 2;
	memset(tail.x, 0, 1000);
	memset(tail.y, 0, 1000);
	tail.size = 0;
	frut.x = rand() % (width - 2);
	frut.y = rand() % (height - 2);
	score = 0;
}


void game_release::draw()
{
	system("cls");
	cout << "SCORE: " << score << endl;
	for (int i = 0; i <= width + 1; ++i)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height - 1; ++i)
	{
		for (int j = 0; j <= width; ++j)
		{
			if (j == 0 || j == width)
				cout << "#";

			if (j == coord.x && i == coord.y)
			{
				cout << "0";
			}
			else if (j == frut.x && i == frut.y) 
			{
				cout << "F";
			}
			else 
			{
				bool gap = false;
				for (int k = 0; k < tail.size; ++k)
				{
					if (tail.x[k] == j && tail.y[k] == i)
					{
						gap = true;
						cout << "o";
					}
				}
				if (!gap)
					cout << " ";
			}

		}
		cout << endl;
	}

	for (int i = 0; i <= width + 1; ++i)
		cout << "#";
	cout << endl;
}

void game_release::input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			CU = LEFT;
			break;

		case 'A':
			CU = LEFT;
			break;

		case 'd':
			CU = RIGHT;
			break;

		case 'D':
			CU = RIGHT;
			break;

		case 'w':
			CU = UP;
			break;

		case 'W':
			CU = UP;
			break;

		case 's':
			CU = DOWN;
			break;

		case 'S':
			CU = DOWN;
			break;

		case 'x':
			game_over = true;
			break;

		case 'X':
			game_over = true;
			break;
		}
	}
}


int game_release::logic()
{
	prv prev;
	bool check = true;
	prev.x = tail.x[0];
	prev.y = tail.y[0];
	tail.x[0] = coord.x;
	tail.y[0] = coord.y;
	for (int i = 1; i < tail.size; ++i)
	{
		prev.x2 = tail.x[i];
		prev.y2 = tail.y[i];
		tail.x[i] = prev.x;
		tail.y[i] = prev.y;
		prev.x = prev.x2;
		prev.y = prev.y2;
	}
	switch (CU)
	{
	case LEFT:
		--coord.x;
		break;
	case RIGHT:
		++coord.x;
		break;
	case UP:
		--coord.y;
		break;
	case DOWN:
		++coord.y;
		break;
	}
	if (coord.x > width - 1 || coord.x < 0)
		game_over = true;

	for (int i = 0; i < tail.size; ++i)
	{
		if (tail.x[i - 1] == coord.x && tail.y[i - 1] == coord.y)
			game_over = true;
	}

	if (coord.y > height - 2 || coord.y < 0)
		game_over = true;
	if (coord.x == frut.x && coord.y == frut.y)
	{
		score += 10;
		frut.x = rand() % (width - 2);
		frut.y = rand() % (height - 2);
		Beep(1000, 50);
		++tail.size;
	}
	return score;
}