#ifndef RUBIKGL
#define RUBIKGL

#include <QWidget>  
#include <QGLWidget>  
#include <QKeyEvent>
#include "state.h"

// GL libraries
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#endif
#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

class Cell{      //сведения о ячейке
public:
    int face, x, y;
    Cell(){}
    Cell(int _face, int _x, int _y): face(_face), x(_x), y(_y){}
};

enum mode                    //x,y,z координаты в 3D модели
{
    mode_x, mode_y, mode_z
};
  
class RubikGLWidget : public QGLWidget   //вращение 3D объекта с использованием библиотеки "OpenGL"
{  
    Q_OBJECT 
    
public:  
    explicit RubikGLWidget(State *_state); //явный конструктор
    ~RubikGLWidget();  //деструктор
    void plane_Rotate(string r, int delay);//поворот в плоскости
    void performRotateView(GLfloat x, GLfloat y, GLfloat z, int delay); //поворот в 3D модели
    State *state;      //указатель на класс, отвечающий за формирование сцены вращения
    
protected:             //функции работы с OpenGL
    void initializeGL();
    void resizeGL(int w, int h);  
    void paintGL();
    void keyPressEvent(QKeyEvent *event); 
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
      
private:  
    bool fullscreen;  //заполнение моделью всего окна
    mode renderMode;  //режим визуализации
    GLfloat rotateDelta, rotateViewX, rotateViewY, rotateViewZ; //координаты для поворота
    int rotateLayer;
    QPoint lastPos;    //запоминание последней точки
    
    void setColor(int color);   //установление цвета
    void drawRect(double sx, double sy, double sz, GLfloat x, GLfloat y, GLfloat w, GLfloat h, int color);//рисование прямоугольников-ячеек
    void drawCell(int face, int x, int y); //рисование границ ячеек
};  

#endif // RUBIKGL

