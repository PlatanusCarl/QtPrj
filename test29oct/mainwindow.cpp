#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myparsers.h"
#include "myopengl.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    parserforsld.loadfile(":/new/mapfiles/qu.sld");
    parserforgeojson.loadfile(":/new/mapfiles/qu.geojson");
    qDebug() <<parserforsld.stylelist.size()<<parserforgeojson.polylist.size();

}
