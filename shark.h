#ifndef SHARK_H
#define SHARK_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

/** another class derived from GameItem that creates a QGraphicsPixmapItem of a shark that
* has the ability to move in relation to the mermaid's location.  Follows the mermaid with a delay
* @author Paige Kehoe */
class Shark: public GameItem {
	public:
		/** Shark constructor
		* @param QPixmap* a pointer to a picture of a shark
		* @param int xl starting x location
		* @param int yl starting y location
		* @param int gx the x location of the mermaid
		* @param int gy the y location of the mermaid */
		Shark(QPixmap *pm, long double xl, long double yl, int gx, int gy);
		/** Shark destructor */
		~Shark();
		/** a function to move in relation to the mermaid's location, move up if she is above the object and down if she is below */
		void move();
		/** a function to set the velocity of the object */
		void setVel(int v);
		/** a function to get the location of the mermaid and update the goal values for the shark */	
		void setGoals(long double wx, long double wy, int c);
		/** x value for location of object */
		long double x;
		/** y value for location of object */
		long double y;
};

#endif
