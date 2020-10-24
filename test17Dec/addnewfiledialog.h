#ifndef ADDNEWFILEDIALOG_H
#define ADDNEWFILEDIALOG_H
#include <QFile>
#include <QFileDialog>
#include "geojsonparser.h"
#include "sldparser.h"

namespace Ui {
class addNewFileDialog;
}

class addNewFileDialog : public QFileDialog
{
    Q_OBJECT

public:
    explicit addNewFileDialog(QWidget *parent = nullptr);
    ~addNewFileDialog();
    void initDia();
    QStringList fileNames;
private:
    Ui::addNewFileDialog *ui;
};

#endif // ADDNEWFILEDIALOG_H
