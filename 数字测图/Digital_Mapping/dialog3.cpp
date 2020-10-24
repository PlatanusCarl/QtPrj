#include "dialog3.h"
#include "ui_dialog3.h"
#include<QMessageBox>

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_calculateButton_clicked()
{
    QString lstring = ui->lEdit->text();
    double L = lstring.toDouble();
    QString nstring = ui->nEdit->text();
    double n = nstring.toDouble();
    QString n1string = ui->n1Edit->text();
    double n1 = n1string.toDouble();

    if(lstring.isEmpty()&&nstring.isEmpty()&&n1string.isEmpty())
    {
        QMessageBox::warning(nullptr,"Warning", "输入有误", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    class3 calculater(n,n1,L);
    calculater.calculate();

    ui->lEdit->setText(QString::number(calculater.L));
    ui->nEdit->setText(QString::number(calculater.n));
    ui->n1Edit->setText(QString::number(calculater.n1));
}

void Dialog3::on_clearButton_clicked()
{
    ui->lEdit->clear();
    ui->nEdit->clear();
    ui->n1Edit->clear();
}

void Dialog3::on_exitButton_clicked()
{
    ui->lEdit->clear();
    ui->nEdit->clear();
    ui->n1Edit->clear();
    this->close();
}
