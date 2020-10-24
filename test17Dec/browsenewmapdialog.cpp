#include "browsenewmapdialog.h"
#include "ui_browsenewmapdialog.h"

browseNewMapDialog::browseNewMapDialog(QWidget *parent) :
    QFileDialog(parent),
    ui(new Ui::browseNewMapDialog)
{
    ui->setupUi(this);
}

browseNewMapDialog::~browseNewMapDialog()
{
    delete ui;
}

void browseNewMapDialog::initDia()
{
    this->setWindowTitle(QString::fromLocal8Bit("浏览新地图"));
    this->setDirectory(".");
    this->setFileMode(QFileDialog::ExistingFiles);
    this->setViewMode(QFileDialog::Detail);
    this->setFixedSize(600,400);
    QStringList filters;
    filters << "*.json *.geojson *.sld *.xml *.shx *.shp";
    this->setNameFilters(filters);
    //if (this->exec())
        fileNames = this->selectedFiles();
}
