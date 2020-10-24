#include "dialog4.h"
#include "ui_dialog4.h"

Dialog4::Dialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);
}

Dialog4::~Dialog4()
{
    delete ui;
}

void Dialog4::on_calculateButton_clicked()
{


    class4 calculater;
    calculater.calculate();
}

void Dialog4::on_clearButton_clicked()
{
    ui->AEdit->clear();
    ui->MEdit->clear();
    ui->gamaEdit->clear();
    ui->alphaEdit->clear();
    ui->deltaEdit->clear();
}

void Dialog4::on_exitButton_clicked()
{
    ui->AEdit->clear();
    ui->MEdit->clear();
    ui->gamaEdit->clear();
    ui->alphaEdit->clear();
    ui->deltaEdit->clear();
    ui->epsilonEdit->clear();
    this->close();
}
