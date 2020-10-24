#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
static int dialtag;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(1000,600);
    ui->setupUi(this);

    {
        ui->dial->setNotchesVisible(true);
        ui->dial->setWrapping(true);
        ui->dial->wrapping();
        ui->dial->setPageStep(45);
        ui->dial->setMinimum(0);
        ui->dial->setMaximum(359);
        ui->dial->setNotchTarget(15);
        ui->dial->setValue(180);
        ui->dial->hide();
        dialtag =0;
    }

    ui->statusBar->showMessage(QString::fromLocal8Bit("Window loading finished"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionexit_triggered()
{
    this->close();
}

void MainWindow::on_actionadd_triggered()
{
    ui->statusBar->showMessage(QString::fromLocal8Bit("Add New"));

    auto *fd = new QFileDialog;
    fd->setWindowTitle(QString::fromLocal8Bit("Add New"));
    fd->setDirectory(".");
    fd->setFileMode(QFileDialog::ExistingFiles);
    fd->setViewMode(QFileDialog::Detail);
    fd->setFixedSize(600,400);
    QStringList filters;
    filters << "*.json *.geojson *.sld"<<"*.json" << "*.geojson" << "*.sld"  ;
    fd->setNameFilters(filters);

    fd->show();

    QStringList fileNames;
    QString str;
    if(fd->exec())
       fileNames = fd->selectedFiles();
    foreach (str,fileNames) {
      if(str.endsWith(".geojson") || str.endsWith(".json"))
      {
          geojsonParser parser(str);
          ui->statusBar->showMessage(QString::fromLocal8Bit("Parsing"));
          parser.loadfile();
          ui->geojsontextBrowser->setText(str);
          ui->statusBar->showMessage(QString::fromLocal8Bit("Loading"));
          QList<GLfloat> list;
          for(int i=0;i <parser.alayer.multipolygonlist.size();i++)
          {
            for(int j= 0;j < parser.alayer.multipolygonlist.at(i).polygonlist.size();j++)
            {
               list =parser.alayer.multipolygonlist.at(i).polygonlist.at(j).polygonvec;
            }
            ui->mygl->updatemap(list);
          }
          ui->statusBar->showMessage(QString::fromLocal8Bit("Loading complete"));
      }
      else if(str.endsWith(".sld") || str.endsWith(".xml"))
      {
          auto sldparser = new sldParser;
          ui->sldtextBrowser->setText(str);
          sldparser->loadfile(str);
      }
    }
}

void MainWindow::on_actionnew_triggered()
{/*
    ui->statusBar->showMessage(QString::fromLocal8Bit("浏览新地图 "));
    browseNewMapDialog *md = new browseNewMapDialog;
    md->initDia();
    md->show();
    QString str;
    qDebug() << md->fileNames;
    foreach (str,md->fileNames) {
      if(str.endsWith(".geojson") || str.endsWith(".json"))
      {
          auto geojsonparser = new geojsonParser;
          geojsonparser->loadfile(str);

      }
      else if(str.endsWith(".sld") || str.endsWith(".xml"))
      {
          auto sldparser = new sldParser;
          sldparser->loadfile(str);
      }
    }
*/
}

void MainWindow::on_actionJPG_triggered()
{
    ui->statusBar->showMessage(QString::fromLocal8Bit("Save as JPG file "));
    ui->mygl->saveAs("JPG");
}

void MainWindow::on_actionPNG_triggered()
{
    ui->statusBar->showMessage(QString::fromLocal8Bit("Save as PNG file "));
    ui->mygl->saveAs("PNG");
}

void MainWindow::on_dial_valueChanged(int value)
{
    ui->statusBar->showMessage(QString::fromLocal8Bit("Rotate")+QString::number(value-180)+QString::fromLocal8Bit("°"));
    ui->mygl->rotate(value-180);
}

void MainWindow::on_RotationButton_clicked()
{
    if(dialtag == 0)
    {
        ui->dial->show();
        ui->statusBar->showMessage(QString::fromLocal8Bit("Rotation on"));
        dialtag = 1;
    }
    else {
        ui->dial->hide();
        ui->statusBar->showMessage(QString::fromLocal8Bit("Rotation off"));
        dialtag = 0;
    }
}

void MainWindow::on_ZoomingButton_clicked()
{
    if(ui->mygl->wheelTag == 0)
    {
        ui->statusBar->showMessage(QString::fromLocal8Bit("Zooming on"));
        ui->mygl->wheelTag =1;
    }
    else {
        ui->statusBar->showMessage(QString::fromLocal8Bit("Zooming off"));
        ui->mygl->wheelTag =0;
    }
}

void MainWindow::on_TravelButton_clicked()
{
    ui->mygl->moveTag = abs(ui->mygl->moveTag -1);
    if(ui->mygl->moveTag == 0)
    {
        ui->statusBar->showMessage(QString::fromLocal8Bit("Motion on"));
        ui->mygl->setCursor(Qt::ArrowCursor);
    }
    else
    {
        ui->statusBar->showMessage(QString::fromLocal8Bit("Motion off"));
        ui->mygl->setCursor(Qt::OpenHandCursor);
    }
}
