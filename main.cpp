#include <QtGui/QApplication>
#include <QTimer>
#include <QPushButton>
#include "mainwindow.h"

/** @mainpage Under The Sea - interactive game
*	@section purpose Purpose/Overview
*	
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;  
    w.show();

    return a.exec();
}