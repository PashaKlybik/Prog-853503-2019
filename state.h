#include <cstdio>
using namespace std;

#ifndef STATE_H

#define STATE_H

enum COLOR                       //перечисление цветов
{
	green, white, red, yellow, orange, blue, black
};

enum FACE                       //перечисление граней
{
	faceD, faceF,faceR, faceB, faceL, faceU
};

enum BAR                        //перечисление граней для комплексного поворота
{
    barU, barD, barL, barR
};

const string faceName[6] = {"BOTTOM", "FRONT", "RIGHT", "BACK", "LEFT", "TOP"};

const string colorString[6] = {"G", "W", "R", "Y", "O", "B"};

const string operations1[] = {"U", "U U U", "D", "D D D", "L", "L L L", "R", "R R R", "F", "F F F", "B", "B B B"};

class State            //класс для хранения сведений о положении и цвете ячеек кубика-Рубика
{
private:

    vector<pair<int, int> > getBarCells(int bar);   // формируем координаты вершин при повороте

    void transBar(int barTo, int faceTo, int barFrom, int faceFrom, int rev);//с учетом координат поворота формируем окрашивание при повороте

    void rotateFace(int face);    //поворот передней грани
	
public:

    int color[7][3][3];      //массив, хранящий сведения о 3-х видимых гранях

    vector<string> history;  //история поворотов

    bool isTopBlue(int x, int y); //проверка на окрашивание ячейки в синий

    void reset();                 //начальное положение кубика

    void random(int times);       //рандомное заполнение кубика

    void clearHistory();          //очищение истории поворотов

    State();
    void rotate(string d);                 //поворот слоя

    void rotateBatch(string seq);          //вращение, которое задается в результате разбиения строки

    void rotateBatch(vector<string> o);    //вращение, которое задается строкой

    void rotatevertically();               //вертикальное вращение

    void rotatehorizontally();             //горизонтальное вращенеи
};

#endif
