#ifndef BUBBLE_H
#define BUBBLE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"
/** A class that inherits from GameItem to create a QGraphicsPixmapItem that is a power up bubble.
* bubbles have the ability to bounce up and down as they move across the screen
* @author Paige Kehoe */
class Bubble: public GameItem {
	public:
		/** Bubble constructor
		* @param QPixmap* a pointer to a picture of a bubble
		* @param int nx starting x location
		* @param int ny starting y location*/
		Bubble(QPixmap *pm, int nx, int ny);
		/** a funciton to move the bubble up and down and it moves from right to left across the screen*/
		void move();
		/** the original location of the bubble */
		long double origin;
		/** a function to set the velocity of the bubble */
		void setVel(int cx, int cy);
		/** a function to count how many times the bubble has moved upward*/
		int move_num;
		/** a function to get the location of the mermaid */
		void setGoals(long double wx, long double wy, int c);

};

#endif
