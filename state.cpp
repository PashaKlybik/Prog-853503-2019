#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "state.h"
using namespace std;


void State::reset()                         //функция для возвращения кубика в исходное состояние
{
	for (int k = 0; k < 6; ++k)
		for (int i = 0; i < 3; ++i) 
			for (int j = 0; j < 3; ++j)
				color[k][i][j] = k;
}


State::State()                             //конструктор класса(начальное состояние кубика)
{
	reset();
}

void State::clearHistory()                 //очищаем историю поворотов кубика
{
	history.clear();
}

void State::random(int times)              //рандомное заполнение кубика-рубика через вращение случайным образом
{
    srand(unsigned(time(0)));
	reset();
	while (times--)
        rotate(operations1[rand() % 12]);
}

void State::rotateFace(int face)                        //окрашивание при повороте передней грани
{
	int tmp[3][3];
	for (int i = 0; i < 3; ++i) 
		for (int j = 0; j < 3; ++j)
			tmp[i][j] = color[face][i][j];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			color[face][j][2 - i] = tmp[i][j];
}


vector<pair<int, int> > State::getBarCells(int bar)    //формируем координаты для поворота
{
	vector<pair<int, int> > p;
	if (bar == barU)
	{
		for (int i = 0; i < 3; ++i)
			p.push_back(make_pair(0, i));
	}
	else if (bar == barD)
	{
		for (int i = 0; i < 3; ++i)
			p.push_back(make_pair(2, i));
	}
	else if (bar == barL)
	{
		for (int i = 0; i < 3; ++i)
			p.push_back(make_pair(i, 0));
	}
	else if (bar == barR)
	{
		for (int i = 0; i < 3; ++i)
			p.push_back(make_pair(i, 2));
	}
	return p;	
}


void State::transBar(int barTo, int faceTo, int barFrom, int faceFrom, int rev = false)    //с учетом координат поворота формируем окрашивание при повороте
{
	vector<pair<int, int> > pTo = getBarCells(barTo);
	vector<pair<int, int> > pFrom = getBarCells(barFrom);
	if (rev) 
		reverse(pFrom.begin(), pFrom.end());
	for (int k = 0; k < 3; ++k)
		color[faceTo][pTo[k].first][pTo[k].second] = 
			color[faceFrom][pFrom[k].first][pFrom[k].second];
}

void State::rotate(string _d)   //поворот грани
{
	history.push_back(_d);
	
	int f = 1;
    if (_d.size() > 1) f = 3;
	char d = _d[0];
	while (f--)
	{
        if (d == 'U')              //поворот верхней грани
		{
			rotateFace(faceU);
			transBar(barU, 6, barU, faceF);
			transBar(barU, faceF, barU, faceR);
			transBar(barU, faceR, barU, faceB);
			transBar(barU, faceB, barU, faceL);
			transBar(barU, faceL, barU, 6);
		}
        else if (d == 'D')         //поворот нижней грани
		{
			rotateFace(faceD);
			transBar(barD, 6, barD, faceF);
			transBar(barD, faceF, barD, faceL);
			transBar(barD, faceL, barD, faceB);
			transBar(barD, faceB, barD, faceR);
			transBar(barD, faceR, barD, 6);
		}
        else if (d == 'L')        //поворот левой грани
		{
			rotateFace(faceL); 
			transBar(barL, 6, barL, faceF);
			transBar(barL, faceF, barL, faceU);
			transBar(barL, faceU, barR, faceB, true);
			transBar(barR, faceB, barL, faceD, true);
			transBar(barL, faceD, barL, 6);
		}
        else if (d == 'R')         //поворот правой грани
		{
			rotateFace(faceR);
			transBar(barR, 6, barR, faceF);
			transBar(barR, faceF, barR, faceD);
			transBar(barR, faceD, barL, faceB, true);
			transBar(barL, faceB, barR, faceU, true);
			transBar(barR, faceU, barR, 6);
		}
        else if (d == 'F')         //поворот передней грани
		{
			rotateFace(faceF);
			transBar(barD, 6, barD, faceU);
			transBar(barD, faceU, barR, faceL, true);
			transBar(barR, faceL, barU, faceD);
			transBar(barU, faceD, barL, faceR, true);
			transBar(barL, faceR, barD, 6);
		}
        else if (d == 'B')        //поворот задней грани
		{
			rotateFace(faceB);
			transBar(barU, 6, barU, faceU);
			transBar(barU, faceU, barR, faceR);
			transBar(barR, faceR, barD, faceD, true);
			transBar(barD, faceD, barL, faceL);
			transBar(barL, faceL, barU, 6, true);
		}
	}
}


void State::rotateBatch(vector<string> o)    //осуществляем поворот на каждый элемент вектора
{
    for (auto k:o){
		rotate(k);
    }
}


bool State::isTopBlue(int x, int y)       //проверка на окрашивание ячейки в синий цвет
{
	return color[faceU][x][y] == blue;
}


void State::rotateBatch(string seq)     //поворот, определяющийся элементами строки
{
	vector<string> o;
	string buf = "";
    for (int i = 0; i < (int)seq.size(); ++i)
		if (seq[i] == ' ')
		{
			o.push_back(buf);
			buf = "";
		}
		else buf += seq[i];

	if (buf != "")
		o.push_back(buf);
	rotateBatch(o);
}

void State::rotatehorizontally()           //вращение по горизонтали
{
    rotateFace(faceU);
    for (int k = 0; k < 3; ++k)
        rotateFace(faceD);
    char tmp[10][10];
    memcpy(tmp, color[faceR], sizeof(tmp));
    memcpy(color[faceR], color[faceB], sizeof(color[faceR]));
    memcpy(color[faceB], color[faceL], sizeof(color[faceB]));
    memcpy(color[faceL], color[faceF], sizeof(color[faceL]));
    memcpy(color[faceF], tmp, sizeof(color[faceF]));
}

void State::rotatevertically()                   //вращение по вертикали
{
    rotateFace(faceF);
    for (int k = 0; k < 3; ++k)
        rotateFace(faceB);  
    char tmp[10][10];
    memcpy(tmp, color[faceR], sizeof(tmp));
    memcpy(color[faceR], color[faceU], sizeof(color[faceR]));
    memcpy(color[faceU], color[faceL], sizeof(color[faceU]));
    memcpy(color[faceL], color[faceD], sizeof(color[faceL]));
    memcpy(color[faceD], tmp, sizeof(color[faceD]));
    rotateFace(faceR);
    rotateFace(faceD);
    rotateFace(faceL);
    rotateFace(faceU);
}
