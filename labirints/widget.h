#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    void DrawLabyrinth();

    int** MakeArray();

    void DeleteArray(int **arr);

    void MakeLabyrinth();

    void MakeLabyrinth2();

    void AreYouWin();

    void DrawNextRect();

    void SeeTheWay();

    void AddToWay(int x, int y);

    bool IsRight(QString str);

    void ButtonsEnabled(bool trueOrFalse);

    void dfs(int x, int y);

    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Widget *ui;
    int **rightLine, **topLine, **isVisited;
    int n, m, startx, starty, finishx, finishy, visitedCells, num, num2;
    QGraphicsScene *scene;
    QGraphicsRectItem *rect1, *rect2;
    bool notDeleted, isSquare;
};

#endif // WIDGET_H
