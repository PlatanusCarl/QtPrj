#include "mainwindow.h"
#include <QApplication>//qt应用程序类

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//声明一个应用程序对象
    MainWindow w;//声明一个窗体
    w.show();//显示窗体

    return a.exec();//一直运行该应用程序
}
