#ifndef BROWSENEWMAPDIALOG_H
#define BROWSENEWMAPDIALOG_H

#include <QFile>
#include <QFileDialog>

namespace Ui {
class browseNewMapDialog;
}

class browseNewMapDialog : public QFileDialog
{
    Q_OBJECT

public:
    explicit browseNewMapDialog(QWidget *parent = nullptr);
    ~browseNewMapDialog();
    void initDia();
    QStringList fileNames;
private:
    Ui::browseNewMapDialog *ui;
};

#endif // BROWSENEWMAPDIALOG_H
