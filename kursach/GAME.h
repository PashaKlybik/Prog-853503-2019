#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>

class game_intro
{
public:
	int intro();
	int game_release_begin();
	int game_over(int);
	int game_win(int);
private:
	void start_game();
	int input();
	void respect();
	void _sound_respect();
	void _sound_game_over();
	void _sound_game_start();
};

class game_release
{
public:
	bool game_over = true;
	void draw();
	void input();
	int logic();
	void setup();
private:
	const int width = 25;
	const int height = 25;
	int score;

	enum control_unit { STOP = 0, LEFT, RIGHT, UP, DOWN, PAUSE };

	control_unit CU;
	typedef struct
	{
		int* x = new int[1000];
		int* y = new int[1000];
		int size = 1;
	}tl;
	tl tail;

	typedef struct
	{
		int x;
		int y;
	}coordinates;
	coordinates coord;

	typedef struct
	{
		int x;
		int y;
	}fruit;
	fruit frut;

	typedef struct
	{
		int x;
		int y;
		int x2;
		int y2;
	}prv;

};