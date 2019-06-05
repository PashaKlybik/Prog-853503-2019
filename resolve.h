#include <cstdio>
#include <vector>
#include <string>
#include "state.h"
using namespace std;

#ifndef RESOLVE_H

#define RESOLVE_H

const int maxSteps = 10000;         //максимальное количество шагов

class requirement                   //класс выполняющий проверку на правильное выполнение шагов решения
{
public:
	int face, x, y, c;
	
	requirement(){}
	requirement(int _face, int _x, int _y, int _c): face(_face), x(_x), y(_y), c(_c) {}
};

class Resolve                  //поиск шагов решения кубика-Рубика
{
private:

    bool valid, asked;

    vector<vector<string> > sol;  //поиск решения за лучшее время

    vector<string> stepFirstLayer(State state);//построение решения для первого слоя
    vector<string> stepFirstLayerformove(State state);

    vector<string> stepSecondLayer(State state);//построение решения для второго слоя
    vector<string> stepSecondLayerformove(State state);

    vector<string> stepThirdLayer(State state);//построение решения для третьего слоя
    vector<string> stepThirdLayerformove(State state);

    vector<string> nosol();// сообщение при неправильном вводе
    
    // получить все возможные решения с количеством шагов меньше максимального
    void getPossibleSolutions(int limit, vector<vector<string> > &sol, string *cur, int cnt);
    void getPossibleSolutionsformove(int limit, vector<vector<string> > &sol, string *cur, int cnt);

    int setMatch(int c1, int c2, int c3, int e1, int e2);// проверить на вхождение с1,с2,с3 в е1,е2
	
public:
    // векторы для вывода шагов для решения кубика-Рубика
    vector<vector<string> > solve(State state);
    vector<vector<string> > solveformove(State state);
};

#endif
