#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "game.h"
using namespace std;


void game_intro::start_game()
{
	system("cls");
	cout << "   #############   ####       ##         ####         ##    ######  ################" << endl;
	cout << "   ##              ## ##      ##        ##  ##        ##   ##       ##              " << endl;
	cout << "   ##              ##  ##     ##       ##    ##       ##  ##        ##              " << endl;
	cout << "   ##              ##   ##    ##      ##      ##      ## ##         ##              " << endl;
	cout << "   #############   ##    ##   ##     ############     ####          ############    " << endl;
	cout << "              ##   ##     ##  ##    ##          ##    ## ###        ##              " << endl;
	cout << "              ##   ##      ## ##   ##            ##   ##   ##       ##              " << endl;
	cout << "   #############   ##       ####  ##              ##  ##    ######  ################" << endl;
	cout << endl;
	cout << "         ############         ####         ####        ####  ################" << endl;
	cout << "         ##        ##        ##  ##        ## ##      ## ##  ##              " << endl;
	cout << "         ##                 ##    ##       ##  ##    ##  ##  ##              " << endl;
	cout << "         ##                ##      ##      ##   ##  ##   ##  ##              " << endl;
	cout << "         ##     #####     ############     ##    ####    ##  ############    " << endl;
	cout << "         ##     ## ##    ##          ##    ##            ##  ##              " << endl;
	cout << "         ##        ##   ##            ##   ##            ##  ##              " << endl;
	cout << "         ############  ##              ##  ##            ##  ################" << endl;
	cout << endl;
	cout << "   Version 6 beta                                 Made by Kostya Akulich O_o" << endl;
	cout << endl;
	_sound_game_start();
}

int game_intro::intro()
{
	start_game();
	return input();
}

int game_intro::input()
{
	char character = 0;
	while (character != 'f' && character != 'p' && character != 'F' && character != 'P')
	{
		system("cls");
		cout << "Hello, to play my game turn on English layout and system sounds)\n Press P to play\n Press F to pay respect)\n";
		character = _getch();
	}

	if (character == 'f' || character == 'F') {
		respect();
		char character = 0;
		while (character != 'P' && character != 'p' && character != 'x' && character != 'X')
		{
			cout << "Press P to play\nPress X to exit\n";
			character = _getch();
		}

		if (character == 'p' || character == 'P')
			return 1;
		if (character == 'X' || character == 'x')
			return 0;
	}
	if (character == 'p' || character == 'P')
		return 1;
}



int game_intro::game_release_begin()
{
	system("cls");
	cout << "Rules of the game:\n Key W --- up\n Key A --- left\n Key D --- right\n Key S --- down\n Key X --- auto die (everyone should have a choice)\n\nPrehistory:\n You play as a small snake. You goal is to eat 100 F's and have a RESPECT).\n";
	system("pause");
	char character = 0;
	while (character != 'm' && character != 'M' && character != 'h' && character != 'H' && character != 'E' && character != 'e') 
	{
		system("cls");
		cout << "Let's play\n Press M to master mode\n Press H to hard mode\n Press E to easy mode\n";
		character = _getch();
	}

	if (character == 'M' || character == 'm')
		return 30;
	if (character == 'H' || character == 'h')
		return 100;
	if (character == 'E' || character == 'e')
		return 140;
}

void game_intro::respect()
{
	cout << "      ###########" << endl;
	cout << "      #         #" << endl;
	cout << "     /****\\     #" << endl;
	cout << "    /**/ __  __ #" << endl;
	cout << "   /**/   .  .  #" << endl;
	cout << "  /**/#     |   #" << endl;
	cout << " /**/ #    ___  #" << endl;
	cout << "/*****###########" << endl;
	_sound_respect();
	return;
}

int game_intro::game_over(int score)
{
	system("cls");
	cout << "                           FINAL SCORE:" << score << endl << endl;
	cout << "   ############         ####         ####        ####  ################" << endl;
	cout << "   ##        ##        ##  ##        ## ##      ## ##  ##              " << endl;
	cout << "   ##                 ##    ##       ##  ##    ##  ##  ##              " << endl;
	cout << "   ##                ##      ##      ##   ##  ##   ##  ##              " << endl;
	cout << "   ##     #####     ############     ##    ####    ##  ############    " << endl;
	cout << "   ##     ## ##    ##          ##    ##            ##  ##              " << endl;
	cout << "   ##        ##   ##            ##   ##            ##  ##              " << endl;
	cout << "   ############  ##              ##  ##            ##  ################" << endl;
	cout << endl;
	cout << "   ############  ##              ##  ################  ##############  " << endl;
	cout << "   ##        ##   ##            ##   ##                ##           ## " << endl;
	cout << "   ##        ##    ##          ##    ##                ##            ##" << endl;
	cout << "   ##        ##     ##        ##     ##                ##           ## " << endl;
	cout << "   ##        ##      ##      ##      ############      ##############  " << endl;
	cout << "   ##        ##       ##    ##       ##                ##  ##          " << endl;
	cout << "   ##        ##        ##  ##        ##                ##   ##         " << endl;
	cout << "   ############         ####         ################  ##    #######   " << endl;
	_sound_game_over();
	char character = 0;
	cout << "Press R if you want to restart\nPress X to exit\n";
	
	while (character != 'R' && character != 'r' && character != 'X' && character != 'x') 
	{
		character = _getch();
	}

	if (character == 'R' || character == 'r')
		return true;
	if (character == 'X' || character == 'x')
		return false;
}

int game_intro::game_win(int score)
{
	system("cls");
	cout << "                           FINAL SCORE:" << score << endl << endl;
	cout << "     ##############   ################  #############  ##############    ################  #############  ##############" << endl;
	cout << "     ##           ##  ##                ##             ##           ##   ##                ##                   ##      " << endl;
	cout << "     ##            ## ##                ##             ##            ##  ##                ##                   ##      " << endl;
	cout << "     ##           ##  ##                ##             ##           ##   ##                ##                   ##      " << endl;
	cout << "     ##############   ############      #############  ##############    ############      ##                   ##      " << endl;
	cout << "     ##  ##           ##                           ##  ##                ##                ##                   ##      " << endl;
	cout << "     ##   ##          ##                           ##  ##                ##                ##                   ##      " << endl;
	cout << "     ##    #######    ################  #############  ##                ################  #############        ##      " << endl;
	cout << endl;
	cout << "                                   ##        ##  ############  ##         ##   ##                     ###########" << endl;
	cout << "                                    ##      ##   ##        ##  ##         ##   ##                     #         #" << endl;
	cout << "                                     ##    ##    ##        ##  ##         ##   ##                    /****\\     #" << endl;
	cout << "                                      ##  ##     ##        ##  ##         ##   ##                   /**/ __  __ #" << endl;
	cout << "                                       ####      ##        ##  ##         ##   ##                  /**/   .  .  #" << endl;
	cout << "                                        ##       ##        ##  ##         ##   ##                 /**/#     |   #" << endl;
	cout << "                                        ##       ##        ##  ##         ##                     /**/ #    ___  #" << endl;
	cout << "                                        ##       ############  #############   ##               /*****###########" << endl;
	_sound_respect();
	char character = 0;
	cout << "Press R if you want to restart\nPress X to exit\n";
	while (character != 'R' && character != 'r' && character != 'X' && character != 'x')
	{
		character = _getch();
	}
	if (character == 'R' || character == 'r')
		return true;
	if (character == 'X' || character == 'x')
		return false;
}


void game_intro::_sound_game_over()
{
	Beep(400, 200);
	Beep(400, 200);
	Beep(400, 200);
	Beep(324, 1000);
	Beep(350, 200);
	Beep(350, 200);
	Beep(350, 200);
	Beep(300, 1000);
	return;
}

void game_intro::_sound_respect()
{
	Beep(400, 300);
	Beep(450, 200);
	Beep(350, 250);
	Beep(400, 1000);
	Beep(100, 50);
	Sleep(55);
	Beep(475, 300);
	Beep(450, 200);
	Beep(350, 250);
	Beep(400, 1000);
	return;
}

void game_intro::_sound_game_start()
{
	Beep(300, 800);
	Beep(225, 800);
	Beep(300, 800);
	Beep(225, 400);
	Beep(320, 400);
	Beep(350, 800);
	Beep(270, 800);
	Beep(350, 800);
	Beep(350, 400);
	Beep(320, 400);
	Beep(300, 800);
	Beep(225, 800);
	Beep(300, 400);
	return;
}

