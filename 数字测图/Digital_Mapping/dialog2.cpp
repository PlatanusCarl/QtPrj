#include "dialog2.h"
#include "ui_dialog2.h"
#include <QMessageBox>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_clearButton_clicked()
{
    ui->x0Edit->clear();
    ui->y0Edit->clear();
    ui->alphaEdit->clear();
    ui->x1Edit->clear();
    ui->y1Edit->clear();
    ui->A1Edit->clear();
    ui->B1Edit->clear();
}

void Dialog2::on_exitButton_clicked()
{
    this->close();
}

void Dialog2::on_runButton_clicked()
{
    QString string1 = ui->x0Edit->text();
    double x0 = string1.toDouble();
    QString string2 = ui->y0Edit->text();
    double y0 = string2.toDouble();
    QString string3 = ui->A1Edit->text();
    double a1 = string3.toDouble();
    QString string4 = ui->B1Edit->text();
    double b1 = string4.toDouble();
    QString string5 = ui->alphaEdit->text();
    double alpha = string5.toDouble();
    QString string6 = ui->x1Edit->text();
    double x1 = string6.toDouble();
    QString string7 = ui->y1Edit->text();
    double y1 = string7.toDouble();
    if(!string1.isEmpty()&&!string2.isEmpty()&&!string5.isEmpty())
    {
        if(!string3.isEmpty()&&!string4.isEmpty())
        {
            class2 calculater(x0,y0,a1,b1,alpha,true);
            calculater.fromAB1toXY1();
            ui->x1Edit->setText(QString::number(calculater.XY1[0]));
            ui->y1Edit->setText(QString::number(calculater.XY1[1]));
            return;
        }
        else if (!string6.isEmpty()&&!string7.isEmpty())
        {
            class2 calculater(x0,y0,x1,y1,alpha,true);
            calculater.fromXY1toAB1();
            ui->A1Edit->setText(QString::number(calculater.AB1[0]));
            ui->B1Edit->setText(QString::number(calculater.AB1[1]));
            return;
        }
    }
    QMessageBox::warning(nullptr,"warning", "输入有误", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}
