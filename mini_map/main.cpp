#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    //声明应用，打开窗口
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //安装翻译器
    QTranslator t ;
    t.load ( ":/qt_zh_CN.qm" );
    a.installTranslator(&t);

    return a.exec();
}
