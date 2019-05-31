#ifndef RUBIK_H
#define RUBIK_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QInputDialog>
#include <QPainter>
#include <QMouseEvent>
#include <QThread>
#include <QPixmap>
#include <QTimer>
#include <QRect>
#include <QRectF>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>

#include "state.h"
#include "resolve.h"
#include "3Dmodel.h"
#include "result.h"

using namespace std;

const int sizeStroke = 5;

namespace cssColor                 //инициализация цветов
{
    const QString red = "#b71234";
    const QString green = "#009b48";
    const QString blue = "#0046ad";
    const QString orange = "#ff5800";
    const QString yellow = "#ffd500";
    const QString white = "#000000";
}

namespace Ui {
class rubik;
}

class Drawing_a_cube                   //рисование кубика-Рубика и его окрашивание
{
public:
    
    int active, color, remain;
    Drawing_a_cube();
    void reset();
    int next();
};

class rubik : public QMainWindow    //задаем главное окно работы с кубиком и его разверткой
{
    Q_OBJECT
    
public:
    explicit rubik(QWidget *parent = 0);       //явный конструктор
    ~rubik();
    pair<int, int> pos, desktop;               //положение ячейки
    void renderFace(QLabel *graph, State *state, int fid);//формируем центральную(переднюю) грань
    void renderFaces(State *state);            //формируем остальные грани(в зависимости от положения кубика)
    void updateResult();                       //обновление результата после очередного вычисления
    int paintFace(QLabel *graph, int fid, int x, int y); //закрашиваем развертку
    void setFace(int fid, char *input);
private slots:                                 //действия по нажатию на кнопки
    
    void on_pushButton_Scramble_clicked();
    void on_pushButton_Play_clicked();
    void on_pushButton_ViewSolution_clicked();
    void on_pushButton_Pause_clicked();
    void on_slider_Progress_sliderMoved(int position);
    void on_pushButton_Repaint_clicked();
    void loadGL();
    void adjustFaces();
    void on_pushButton_Input_clicked();
    
protected:
    
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    
private:
    Ui::rubik *ui;
    Drawing_a_cube  *paint;
    State *state;
    RubikGLWidget *glW;
    string env;
    char originalFace[1000];
    vector<vector<string> > result;
    vector<vector<string> > resultformove;
    vector<State> stateSteps;
    vector<string> steps;

};

#endif // RUBIK_H
