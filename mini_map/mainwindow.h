#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "gl.h"
#include "geojsonparser.h"
#include "sldparser.h"

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

    void on_actionexit_triggered();

    void on_actionadd_triggered();

    void on_actionnew_triggered();

    void on_actionJPG_triggered();

    void on_actionPNG_triggered();

    void on_dial_valueChanged(int value);

    void on_RotationButton_clicked();

    void on_ZoomingButton_clicked();

    void on_TravelButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
