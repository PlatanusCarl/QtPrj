#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialog4.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action1_2_triggered();

    void on_action1_21_triggered();

    void on_actiontouying_triggered();

    void on_actionco_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
