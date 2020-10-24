#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action1_2_triggered()
{
    static Dialog1 *dia = new Dialog1(this);
    dia->show();
}

void MainWindow::on_action1_21_triggered()
{
    static Dialog2 *dia = new Dialog2(this);
    dia->show();
}

void MainWindow::on_actiontouying_triggered()
{
    static Dialog3 *dia = new Dialog3(this);
    dia->show();
}

void MainWindow::on_actionco_triggered()
{
    static Dialog4 *dia = new Dialog4(this);
    dia->show();
}
