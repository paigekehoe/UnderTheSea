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
#include <QPixmap>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QGraphicsItem>
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
#include <QLinkedList>
#include <QLineEdit>
#include <QMainWindow>
#include <QVector>
#include <QGraphicsPixmapItem>
#include <iostream>
#include "shark.h"
#include "tiki.h"
#include "fire.h"
#include "bubble.h"
#include "mermaid.h"
#include "boat.h"
#include "gameitem.h"


#define WINDOW_MAX_X 400
#define WINDOW_MAX_Y 200

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
			/** MainWindow constructor... where all the magic happens*/
    explicit MainWindow();
    /** MainWindow destructor */
    ~MainWindow();
		/** a function to show the MainWindow and all of its components */
    void show();
protected:
	void keyPressEvent(QKeyEvent *k);
	void mousePressEvent(QMouseEvent *e);
private:
		void createTitle();
		void createMenuArea();
		void createStartArea();
		/** scene for gameplay*/
    QGraphicsScene *scene;
    /** QGraphicsView for the scene */
    QGraphicsView *view;
		QMainWindow *mainW; 
		QDockWidget *menuArea, *scoreArea, *titleArea;
		QPushButton	*start, *pause, *stop, *quit;
		QWidget *menu, *welcome;
		QLineEdit *player_name;
		Mermaid *mermaid;
		Tiki *tiki;
		QTimer* timer;
		QLabel	*level_label, *lives_label, *score_label, *w, *i, *name_label;
		QPixmap *shark_pic, *bubble_pic, *fire_pic, *boat_pic;//, *welcome_screen;
		QLineEdit *playerName;
		//QVector<QGraphicsPixmapItem> on_screen;
		int level;
		int score;
		int lives;
		int count;
		bool shark_here;
		bool game_in_play;
		QLinkedList<GameItem*> on_screen;
		QLinkedList<Shark*> sharks;
		
		void levelUp();
		void collision(GameItem* item);
		void scoreFunct(int points);
		void loseLife();
		void gainLife();
signals:
	void death();
	//void  collision signals?
public slots:
	void handleTimer();
	void gameOver();
	void startGame();
	void pauseGame();
	void newGame();
	void stopGame();
	void quitGame();
	void resumeTime();
};


#endif
