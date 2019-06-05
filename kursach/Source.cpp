#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "game.h"
const int HI_score = 100;

int main()
{
	int hard_of_game;
	bool check_game = true;
	game_intro intr;
	game_release game_r;
	check_game = intr.intro();
	if (!check_game)
		return 0;
	while (check_game)
	{
		int score = 0;
		hard_of_game = intr.game_release_begin();
		game_r.setup();
		while (!game_r.game_over) 
		{
			game_r.draw();
			Sleep(hard_of_game);
			game_r.input();
			score = game_r.logic();
			if (score == HI_score)
				break;
		}
		if (score < HI_score) 
		{
			check_game = intr.game_over(score);
			game_r.game_over = false;
		}
		else
		{
			check_game = intr.game_win(score);
			game_r.game_over = false;
		}
	}
	return 0;
}