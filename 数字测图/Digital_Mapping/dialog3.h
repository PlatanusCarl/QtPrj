#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>
#include "class3.h"


namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();

private slots:
    void on_calculateButton_clicked();

    void on_clearButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::Dialog3 *ui;
};

#endif // DIALOG3_H
