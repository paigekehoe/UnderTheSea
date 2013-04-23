#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QPicture>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QCoreApplication>
#include <QDockWidget>
#include <QMessageBox>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QColor>
#include <QLabel> 
#include <QtGlobal>
#include <QTimer>
#include <QLayout>
#include <QBoxLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QListView>
#include <QList>
#include <QLineEdit>
#include <QMainWindow>
#include <QVector>
#include <QGraphicsPixmapItem>
#include <iostream>
#include "shark.h"
#include "tiki.h"
#include "bubble.h"
#include "mermaid.h"
#include "boat.h"


#define WINDOW_MAX_X 400
#define WINDOW_MAX_Y 250

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
			/** MainWindow constructor... where all the magic happens*/
    explicit MainWindow();
    /** MainWindow destructor */
    ~MainWindow();
		/** a function to show the MainWindow and all of its components */
    void show();
private:
		void createStartScreen();
		void createMenuArea();
		void createScoreArea();
		/** scene for gameplay*/
    QGraphicsScene *scene;
    /** QGraphicsView for the scene */
    QGraphicsView *view;
		QMainWindow *mainW; 
		QDockWidget *menuArea, *scoreArea;
		QPushButton	*start, *pause, *stop, *quit;
		QWidget *menu;
		QLineEdit *player_name;
		Mermaid *mermaid;
		QTimer* timer;
		QLabel	*level_label, *lives_label, *score_label;
		//QVector<QGraphicsPixmapItem> on_screen;
		int level;
		int score;
		int lives;
		int count;
		
signals:
	void levelUp();
public slots:
	void counter();
	void loseLife();
	void gainLife();
	void scoreFunct(int points);
	void startGame();
	void pauseGame();
	void stopGame();
	void quitGame();
};

#endif
