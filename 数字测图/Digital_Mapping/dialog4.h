#ifndef DIALOG4_H
#define DIALOG4_H

#include <QDialog>
#include "class4.h"
namespace Ui {
class Dialog4;
}

class Dialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog4(QWidget *parent = nullptr);
    ~Dialog4();

private slots:
    void on_calculateButton_clicked();

    void on_clearButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::Dialog4 *ui;
};

#endif // DIALOG4_H
