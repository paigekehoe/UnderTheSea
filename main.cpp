#include <QtGui/QApplication>
#include <QTimer>
#include <QPushButton>
#include "mainwindow.h"

/** @mainpage Under The Sea - interactive game
*	@section purpose Purpose/Overview
* This is a fun and simple video game for a user's enjoyment. It was written as an introduction to basic Qt programming.
*	
*/
void QGraphicsView::scrollContentsBy(int, int)
{
    //don't do anything haha!
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;  
    w.show();

    return a.exec();
}
