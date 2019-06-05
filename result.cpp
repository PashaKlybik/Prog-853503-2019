#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent) :    //задаем форму для вывода результата
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    ui->textEdit->setText("");
    setWindowTitle("Input");
}

Result::~Result()
{
    delete ui;
}

void Result::output(string res)            //вывод сообщения о результатах
{
    ui->textEdit->setText(res.c_str());
    setWindowTitle("Solution (Homework mode)");
    show();    
}

void Result::on_pushButton_Cancel_clicked()  //слот для осуществления закрытие формы
{
    buffer = "";
    close();
}

void Result::on_pushButton_OK_clicked()   //слот для осуществления повторного вывода шагов
{
    buffer = ui->textEdit->toPlainText();
    close();
}
