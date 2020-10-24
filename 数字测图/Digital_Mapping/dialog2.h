#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include "class2.h"

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

private slots:

    void on_clearButton_clicked();

    void on_exitButton_clicked();

    void on_runButton_clicked();

private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H
