#include "widget.h"
#include "ui_widget.h"
#include "QPainter"
#include <QRandomGenerator>
#include <stdio.h>
#include <QMessageBox>
#include <string.h>
#include <QShortcut>
#include <QKeySequence>
#include <QTime>
#include <QGraphicsRectItem>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    n = m = 0;
    isSquare = false;
    notDeleted = false;                  //Были ли удалены массивы в прошлый раз
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);  // Установка графической сцены в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Установка сглаживания
    scene->setSceneRect(0,0,760,1010);  // Установка области графической сцены
    ButtonsEnabled(false);              // Делаем недоступными все кнопки, кроме кнопки для генерации лабиринта
}

Widget::~Widget()
{
    if (notDeleted) //Если массивы не были удалены, удалить
    {
        DeleteArray(rightLine); //Вызов функции удаления двумерного массива m*n
        DeleteArray(topLine);
    }
    delete scene;
    delete ui;
}

void Widget::DrawLabyrinth()
{
     scene->clear();                    // Очищение графической сцены
     scene->addRect(num,num2,m*20,n*20);   // Рамка лабиринта
     isSquare = false;                  // Закрашенных клеточек нет
     for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (rightLine[i][j] == 0)   // Если линия справа для клетки есть, добавить её
            {
                scene->addLine(20*i+20+num,20*j+num2,20*i+20+num,20*j+20+num2);
            }
            if (topLine[i][j] == 0)     // Если линия сверху для клетки есть, добавить её
            {
                scene->addLine(20*i+num,20*j+num2,20*i+20+num,20*j+num2);
            }
        }
}

int** Widget::MakeArray()
{
    /* Создание двумерного массива */
    int **arr = new int*[m + 1];
    for (int i = 0; i <= m; i++)
        arr[i] = new int[n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            arr[i][j] = 0;
    return arr;
}

void Widget::DeleteArray(int **arr)
{
    /* Удаление двумерного массива */
    for (int i = 0; i <= m; i++)
        delete arr[i];
    delete arr;
}

void Widget::on_pushButton_clicked()
{
    ButtonsEnabled(false);          // Делаем недоступными все кнопки, кроме кнопки для генерации лабиринта
    if (notDeleted)                 // Если массивы не были удалены, удалить
    {
        DeleteArray(rightLine);
        DeleteArray(topLine);
        notDeleted = false;
    }
    /* Если введены не целые числа, сообщить о неверном вводе */
    if (!IsRight(ui->textEdit->toPlainText()) || !IsRight(ui->textEdit_2->toPlainText()))
    {
        ui->textEdit->clear();
        ui->textEdit_2->clear();
        QMessageBox::information(this, "", "Введите два числа от 2 до 50.");
    }
    else    // Иначе создать лабиринт
    {
        n = ui->textEdit->toPlainText().toInt();
        m = ui->textEdit_2->toPlainText().toInt();
        notDeleted = true;
        topLine = MakeArray();
        rightLine = MakeArray();
        int whatWay = qrand() % 5;
        num = -120 + (50 - m) * 10;
        num2 = (37 - n) * 10;
        if (num2 < 0)
            num2 = 0;
        if (whatWay == 3)   // Выбор способа генерации лабиринта
            MakeLabyrinth();
                else
                    MakeLabyrinth2();
        DrawLabyrinth();    // Рисование лабиринта
        ui->pushButton_6->setEnabled(true); // Сделать доступной кнопку
    }
}

bool Widget::IsRight(QString str)
{
    /*  Проверка, правильная ли строка введена.
    Строка должна содержать только целое число от 2 до 50.*/
    if (str.length() == 0)
        return false;           // Если ничего не введено, строка неверная
    if (str == "1" || str == "0")
            return false;       // Если введено число 1 или 0, строка неверная
    for (int i = 0; i < str.length(); i++)
            if (str[i] <'0' || str[i]>'9')
                return false;   // Если встретилось что-то, кроме цифр, строка неверная
    int number = str.toInt();
    if (number > 50)
        return false;           // Если число больше 50, строка неверная
    return true;                // Если ошибки найдены не были, строка верная
}

void Widget::MakeLabyrinth()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            int whereToGo = rand() % 2;
            /* Случайным образом выбираем, убрать стену сверху или справа */
            if (whereToGo == 0)     // Если хотим убрать стену сверху,
            {
                if (j == 0)         // если стену сверху убрать нельзя,
                    whereToGo = 1;  // решаем убрать стену справа
            }
            else
            if (whereToGo == 1)     // Если хотим убрать стену справа,
            {
                if (i == m - 1)     // если стену справа убрать нельзя,
                    whereToGo = 0;  // решаем убрать стену сверху
            }
            switch(whereToGo)
            {
                case(0):
                topLine[i][j] = 1;  // Убираем стену сверху
                break;
                case(1):
                rightLine[i][j] = 1;    // Убираем стену справа
                break;
            }
        }
    /* Для правой верхней клетки нельзя убрать ни стену сверху,
     * ни стену слева, но одна из стен будет удалена, поэтому
     * нужно её вернуть */
    topLine[m - 1][0] = 0;
    rightLine[m - 1][0] = 0;
}

void Widget::MakeLabyrinth2()
{
    /* Случайным образом выбираем координаты стартовой клетки */
    int x = qrand() % m;
    int y = qrand() % n;
    isVisited = MakeArray();    // Массив для отметок, была ли посещена клетка
    visitedCells = 0;           // Количество посещённых клеток
    dfs(x,y);                   // Запуск поиска в глубину для удаления стенок лабиринта
    DeleteArray(isVisited);     // Удаление созданного массива
}

void Widget::dfs(int x, int y)
{
    if (visitedCells == n*m)
        return;             // Если все клетки посещены, не идти дальше
    visitedCells++;         // Увеличение посещённых клеток на 1
    isVisited[x][y] = 1;    // Отметка о посещении текущей клетки
    int whatWay;            // Какой путь вабрать
    bool ways[4];           // Был ли выбран путь
    for (int i = 0; i < 4; i++)
        ways[i] = false;
    int wayNumber[4];       // Номер следующего пути
    for (int i = 0; i < 4; i++)
    {
        whatWay = qrand() % 4;
        while (ways[whatWay])
            whatWay = qrand() % 4;
        wayNumber[i] = whatWay;
        ways[whatWay] = true;
    }
    for (int i = 0; i < 4; i++)
    {
        /* Если можно пойти влево, удалить стену и пойти влево */
        if (wayNumber[i] == 0 && x >= 1 && isVisited[x-1][y] == 0)
        {
            rightLine[x-1][y] = 1;
            dfs(x-1,y);
        }
        /* Если можно пойти вправо, удалить стену и пойти вправо */
        if (wayNumber[i] == 1 && x < m-1 && isVisited[x+1][y] == 0)
        {
            rightLine[x][y] = 1;
            dfs(x+1,y);
        }
        /* Если можно пойти вверх, удалить стену и пойти вверх */
        if (wayNumber[i] == 2 && y >= 1 && isVisited[x][y-1] == 0)
        {
            topLine[x][y] = 1;
            dfs(x,y-1);
        }
        /* Если можно пойти вниз, удалить стену и пойти вниз */
        if (wayNumber[i] == 3 && y < n-1 && isVisited[x][y+1] == 0)
        {
            topLine[x][y+1] = 1;
            dfs(x,y+1);
        }
    }
}


void Widget::on_pushButton_6_clicked()
{
    /* Получение случайных координат старта и финиша */
    startx = qrand() % m;
    starty = qrand() % n;
    finishx = qrand() % m;
    finishy = qrand() % n;
    /* Пока старт совпадает с финишем, получать новые координаты финиша */
    while ((startx == finishx) && (starty == finishy))
    {
        finishx = rand() % m;
        finishy = rand() % n;
    }
    if (isSquare)   // Если есть закрашенные клеточки
    {
        DrawLabyrinth();
    }
    isSquare = true;    // Закрашенные клеточки есть
    /* Добавление зелёной клеточки-старта*/
    rect1 = scene->addRect(startx*20+2+num,starty*20+2+num2,16,16);
    rect1->setBrush(Qt::green);
    QPen *pen = new QPen();
    pen->setColor(Qt::green);
    rect1->setPen(*pen);
    /* Добавление синей клеточки-финиша*/
    rect2 = scene->addRect(finishx*20+2+num,finishy*20+2+num2,16,16);
    rect2->setBrush(Qt::blue);
    pen->setColor(Qt::blue);
    rect2->setPen(*pen);
    /* Делаем доступными кнопки для поиска пути */
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
}

void Widget::ButtonsEnabled(bool trueOrFalse)
{
    /* Установка доступности кнопок */
    ui->pushButton_2->setEnabled(trueOrFalse);
    ui->pushButton_3->setEnabled(trueOrFalse);
    ui->pushButton_4->setEnabled(trueOrFalse);
    ui->pushButton_5->setEnabled(trueOrFalse);
    ui->pushButton_6->setEnabled(trueOrFalse);
    ui->pushButton_7->setEnabled(trueOrFalse);
}

void Widget::AreYouWin()
{
    /* Проверка, дошёш ли игрок до финиша */
    if (startx == finishx && starty == finishy)   // Если текущее положение = финишу,
    {
        ButtonsEnabled(false);  // Сделать кнопки недоступными,
        QMessageBox::information(this, "", "Вы победили!!!");   // сообщить о победе,
        scene->clear();     // очистить графическую сцену
    }
}

void Widget::on_pushButton_5_clicked()
{
    if (topLine[startx][starty] == 1)   // Если можно пойти вверх, идти
    {
        starty--;
        DrawNextRect();     // Закрасить клеточку пройденного пути
    }
    AreYouWin();    // Проверка, не победил ли ещё игрок
}

void Widget::on_pushButton_3_clicked()
{
    if (topLine[startx][starty+1] == 1)     // Если можно пойти вниз, идти
    {
        starty++;
        DrawNextRect();     // Закрасить клеточку пройденного пути
    }
    AreYouWin();    // Проверка, не победил ли ещё игрок
}

void Widget::on_pushButton_2_clicked()
{
    if (rightLine[startx][starty] == 1)     // Если можно пойти вправо, идти
    {
        startx++;
        DrawNextRect();     // Закрасить клеточку пройденного пути
    }
    AreYouWin();    // Проверка, не победил ли ещё игрок
}

void Widget::on_pushButton_4_clicked()
{
    if (rightLine[startx-1][starty] == 1)   // Если можно пойти влево, идти
    {
        startx--;
        DrawNextRect();     // Закрасить клеточку пройденного пути
    }
    AreYouWin();    // Проверка, не победил ли ещё игрок
}

void Widget::DrawNextRect()
{
    /* Клетку, которую игрок покидает, делаем жёлтой */
    rect1->setBrush(Qt::yellow);
    QPen *pen = new QPen();
    pen->setColor(Qt::yellow);
    rect1->setPen(*pen);
    /* Рисуем зелёную текущую клетку */
    rect1 = scene->addRect(startx*20+2+num,starty*20+2+num2,16,16);
    rect1->setBrush(Qt::green);
    pen->setColor(Qt::green);
    rect1->setPen(*pen);
}

void Widget::SeeTheWay()
{
    /* Создаём очередь, в которую будут записаны координаты */
    int *quex = new int[n*m];
    int *quey = new int[n*m];
    int queBegin = 0, queEnd = 0, x, y;
    /* Записываем в очередь координаты старта */
    quex[queBegin] = startx;
    quey[queBegin] = starty;
    int **Way = MakeArray();    // Массив количеств шагов от старта до клетки [i][j]
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            Way[i][j] = -1;     // Помечаем все клетки лабиринта как непосещённые
    Way[startx][starty] = 0;    // Из стартовой клетки в стартовую 0 шагов
    while (Way[finishx][finishy] == -1)     // Пока не посетили клетку финиша
    {
        /* Берём координаты из очереди */
        x = quex[queBegin];
        y = quey[queBegin];
        if (x >= 1 && rightLine[x-1][y] == 1 && Way[x-1][y] == -1)  // Если можно пойти влево,
        {
            queEnd++;
            quex[queEnd] = x - 1;   // добавить в очередь
            quey[queEnd] = y;       //          новые координаты,
            Way[x-1][y] = Way[x][y] + 1;    // записать количество шагов до клетки
        }
        if (y >= 1 && topLine[x][y] == 1 && Way[x][y-1] == -1)      // Если можно пойти вверх,
        {
            queEnd++;
            quex[queEnd] = x;       // добавить в очередь
            quey[queEnd] = y - 1;   //          новые координаты,
            Way[x][y-1] = Way[x][y] + 1;    // записать количество шагов до клетки
        }
        if (x < m-1 && rightLine[x][y] == 1 && Way[x+1][y] == -1)   // Если можно пойти вправо,
        {
            queEnd++;
            quex[queEnd] = x + 1;   // добавить в очередь
            quey[queEnd] = y;       //          новые координаты,
            Way[x+1][y] = Way[x][y] + 1;    // записать количество шагов до клетки
        }
        if (y < n-1 && topLine[x][y+1] == 1 && Way[x][y+1] == -1)   // Если можно пойти вниз,
        {
            queEnd++;
            quex[queEnd] = x;       // добавить в очередь
            quey[queEnd] = y + 1;   //          новые координаты,
            Way[x][y+1] = Way[x][y] + 1;    // записать количество шагов до клетки
        }
        queBegin++;
    }
    x = finishx;
    y = finishy;
    /* Пока текущие координаты не совпали со стартом,
     * ищем клетку, из которой пришли в текущую */
    while (x != startx || y != starty)
    {
        if (x >= 1 && rightLine[x-1][y] == 1 && Way[x-1][y] == Way[x][y]-1) // Проверка клетки слева
            x--;
        else
            if (x < m-1 && rightLine[x][y] == 1 && Way[x+1][y] == Way[x][y]-1)  // Проверка клетки справа
                x++;
        else
            if (y >= 1 && topLine[x][y] == 1 && Way[x][y-1] == Way[x][y]-1) // Проверка клетки сверху
                y--;
        else
            if (y < n-1 && topLine[x][y+1] == 1 && Way[x][y+1] == Way[x][y]-1)  // Проверка клетки снизу
                y++;
        if (x != startx || y != starty)    // Если ещё не старт,
            AddToWay(x, y);                //          нарисовать клетку пути
    }
    DeleteArray(Way);   // Удалить созданный ранее массив
}

void Widget::AddToWay(int x, int y)
{
    /*  Добавление серой клеточки пути, найденного программой */
    QGraphicsRectItem *rect = scene->addRect(x*20+2+num,y*20+2+num2,16,16);
    rect->setBrush(Qt::gray);
    QPen *pen = new QPen();
    pen->setColor(Qt::gray);
    rect->setPen(*pen);
}

void Widget::on_pushButton_7_clicked()
{
    SeeTheWay();    // Показать путь
}
