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
#include <fstream>
#include <sstream>
#include <string>
#include "shark.h"
#include "tiki.h"
#include "fire.h"
#include "bubble.h"
#include "mermaid.h"
#include "boat.h"
#include "gameitem.h"


#define WINDOW_MAX_X 400
#define WINDOW_MAX_Y 200

/** A MainWindow class that inherits from QWidget and holds a QMainWindow object.  In this
* class all gameplay is implemented.  When a user enters his or her name, he or she can start
* playing as a Mermaid that moves up and down on the left hand side of the screen
* and is controlled through the up and down arrow keys.  During gameplay various objects
* randomly generate and "attack" the mermaid.  If hit, she looses lives.  Once all the lives
* are gone the game is over and the player can try again.  The longer the user plays, the
* faster the objects move, so be ready for some very fast sharks if you are good at this game!
* @author Paige Kehoe
*/

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
	/** overwritten keyPressEvent function to take in key presses to control mermaid movement with up and down arrow 
	* @param QKeyEvent the key being pressed */
	void keyPressEvent(QKeyEvent *k);
	/** overwritten mousePressEvent to disable scrolling 
	* @param QMouseEvent the click of the mouse */
	void mousePressEvent(QMouseEvent *e);
private:
		/** function to create the top bar containing the title and eventually the user's name */
		void createTitle();
		/** funciton to create all of the buttons, options, and labels in the menu area - this includes QPushButton start, pause, end game, and quit */
		void createMenuArea();
		/** function to create the start screen holding instructions for gameplay and a QLineEdit for the user to enter his or her name */
		void createStartArea();
		/** scene for gameplay*/
    QGraphicsScene *scene;
    /** QGraphicsView for the scene */
    QGraphicsView *view;
    /** QMainWindow for the game */
		QMainWindow *mainW; 
		/** Dockwidgets to be added to the top and bottom of the mainwindow */
		QDockWidget *menuArea, *scoreArea, *titleArea;
		/** QPushButtons to control gameplay - part of the menu, they function like their titles suggest */
		QPushButton	*start, *pause, *stop, *quit, *scores_button;
		/** QWidgets for the start screen - added to the scene in the beginning */
		QWidget *menu, *welcome, *scores_widget;
		/** the area in which the player must enter his or her name to play the game */
		QLineEdit *player_name;
		/** The Little Mermaid herself - you (or the player) - to be controlled by the user */
		Mermaid *mermaid;
		/** The TIKIMAN! He will shoot at you with balls of fire so beware */
		Tiki *tiki;
		/** The timer that animates everything in the game */
		QTimer* timer;
		/** Labels for information to be displayed throughout gameplay - levels, lives, score, name. W and I are pictures to be displayed in the start screen */
		QLabel	*level_label, *lives_label, *score_label, *w, *i, *name_label;
		/** Picture pointers for all of the QGraphicsPixmapItems in gameplay */
		QPixmap *shark_pic, *bubble_pic, *fire_pic, *boat_pic;
		/** label holding the player's name */
		QLabel *playerName;
		/** variable for the level the player is on */
		int level;
		/** integer variable for the score */
		int score;
		/** integer variable for the number of lives a player has */
		int lives;
		/** integer variable to count number of timeout()s */
		int count;
		/** boolean to tell if a shark is on screen- true means on screen*/
		bool shark_here;
		/** boolean variable to tell if a game is in play - true means in play */
		bool game_in_play;
		/** a boolean variable to tell if the start button has been pressed while a game is already being played */
		bool repeat;
		/** boolean variable to check if the game already has high scores */
		bool firstGame;
		/** QLinkedList to hold pointers to the Game Items that are on screen */
		QLinkedList<GameItem*> on_screen;
		/** adding a level to int level and displaying it on screen */
		void levelUp();
		/** a function to modify and update score */
		void scoreFunct(int points);
		/** a function to take away a life and output it to screen */
		void loseLife();
		/** a function to add a life and output this development */
		void gainLife();
		/** Shark object's velocity */
		long double sharkVel;
		/** Bubble object's velocity */
		long double bubbleVelX, bubbleVelY;
		/** Boat object's velocity */
		long double boatVelY;
		/** fireball's velocity */
		long double fireVelY, fireVelX;
		/** player's name */
		std::string name;
		
signals:
	/** signal emitted when lives=0, aka you are DEAD MEAT */
	void death();
	
public slots:
	/** a funciton to run gameplay and animation, randomly adds GameItem's to the screen and moves them according to thier individual move() functions */
	void handleTimer();
	/** a function to let the player know he sucks and has died. Don't worry though, it gives you the option to start again, or to quit */
	void gameOver();
	/** a function to start the game, checks for a player name, sets starting velocities and starts the timer */
	void startGame();
	/** a function to temporarily suspend gameplay - stops the timer */
	void pauseGame();
	/** a function to start a brand new game */
	void newGame();
	/** a function to end the current game but not exit the program */
	void stopGame();
	/** a function to exit the entire program */
	void quitGame();
	/** a function to restart the timer */
	void resumeTime();
};


#endif
