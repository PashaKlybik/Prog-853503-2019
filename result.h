#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class Result;
}

//класс для вывода окна с необходимыми шагами для решения
class Result : public QDialog
{
    Q_OBJECT
    
public:
    explicit Result(QWidget *parent = 0);
    ~Result();
    void output(string res);
    QString buffer;
    
private slots:
    void on_pushButton_Cancel_clicked();
    void on_pushButton_OK_clicked();
    
private:
    Ui:: Result *ui;
};

#endif // RESULT_H
