#ifndef BOAT_H
#define BOAT_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"
/** A class that derives from GameItem that creates a QGraphicsPixmap item called boat.
* Boat objects simply move across the top of the screen like a boat
* @author Paige Kehoe */

class Boat: public GameItem{
	public:
		/** Boat itemp constructor 
		* @param QPixmap a picture of a boat
		* @param int x the boat's starting location
		* @param int y the boat's starting location */
		Boat(QPixmap *pm, int x, int y);
		/** Boat destructor */
		~Boat();
		/** a function to move the boat across the top of the scene */
		void move();
		/** a function to set the boat's velocity */
		void setVel(int cx);
		/**a function to check if the boat is still on screen
		@return bool true if still on scree, and false if off of the screne */
		bool onScreen();
		/** a function to get the location of the mermaid */
		void setGoals(long double wx, long double wy, int c);
};

#endif
