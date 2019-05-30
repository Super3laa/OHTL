#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   // setFixedSize(500,500);
    w.setFixedSize(w.width(),w.height());
    w.setWindowTitle("Overhead transmission line");
    //Done By Alaa Essam

    return a.exec();
}
