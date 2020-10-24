#include "addnewfiledialog.h"
#include "ui_addnewfiledialog.h"

addNewFileDialog::addNewFileDialog(QWidget *parent) :
    QFileDialog(parent),
    ui(new Ui::addNewFileDialog)
{
    ui->setupUi(this);
}

addNewFileDialog::~addNewFileDialog()
{
    delete ui;
}

void addNewFileDialog::initDia()
{
    this->setWindowTitle(QString::fromLocal8Bit("添加新文件"));
    this->setDirectory(".");
    this->setFileMode(QFileDialog::ExistingFiles);
    this->setViewMode(QFileDialog::Detail);
    this->setFixedSize(600,400);
    QStringList filters;
    filters << "*.json" << "*.geojson" << "*.sld" << "*.shx" << "*.shp"<< "*.json *.geojson *.sld *.shx *.shp";
    this->setNameFilters(filters);
    if (this->exec())
    fileNames = this->selectedFiles();
    qDebug() << this->selectedFiles();
}
