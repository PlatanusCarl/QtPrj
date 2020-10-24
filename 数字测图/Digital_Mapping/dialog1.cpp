#include "dialog1.h"
#include "ui_dialog1.h"
#include <QMessageBox>

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_calculateButton_clicked()
{
    QString Lstring = ui->longitudeEdit->text();
    double L  = Lstring.toDouble();
    QString Bstring = ui->latitudeEdit->text();
    double B  = Bstring.toDouble();
    QString Hstring = ui->heightEdit->text();
    double H = Hstring.toDouble();
    QString Xstring = ui->xEdit->text();
    double X = Xstring.toDouble();
    QString Ystring = ui->yEdit->text();
    double Y = Ystring.toDouble();
    QString Zstring = ui->zEdit->text();
    double Z = Zstring.toDouble();
    if(!Lstring.isEmpty()&&!Bstring.isEmpty()&&!Hstring.isEmpty())
    {
        class1 calculater(L,B,H,false);
        calculater.fromLBHtoXYZ();
        ui->xEdit->setText(QString::number(calculater.XYZ[0]));
        ui->yEdit->setText(QString::number(calculater.XYZ[1]));
        ui->zEdit->setText(QString::number(calculater.XYZ[2]));
        return;
    }
    else if(!Xstring.isEmpty()&&!Ystring.isEmpty()&&!Zstring.isEmpty())
    {
        class1 calculater(X,Y,Z,true);
        calculater.fromXYZtoLBH();
        ui->longitudeEdit->setText(QString::number(calculater.LBH[0]));
        ui->latitudeEdit->setText(QString::number(calculater.LBH[1]));
        ui->heightEdit->setText(QString::number(calculater.LBH[2]));
        return;
    }
    QMessageBox::warning(nullptr,"warning", "输入有误", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void Dialog1::on_exitButton_clicked()
{
    ui->longitudeEdit->clear();
    ui->latitudeEdit->clear();
    ui->heightEdit->clear();
    ui->xEdit->clear();
    ui->yEdit->clear();
    ui->zEdit->clear();
    this->close();
}

void Dialog1::on_clearButton_clicked()
{
    ui->longitudeEdit->clear();
    ui->latitudeEdit->clear();
    ui->heightEdit->clear();
    ui->xEdit->clear();
    ui->yEdit->clear();
    ui->zEdit->clear();
}
