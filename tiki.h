#ifndef TIKI_H
#define TIKI_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

/** A class derived from GameItem to cream a QGraphicsPixmapItem that is a tiki man
* he is stationary on the screen and does nothing */
class Tiki: public GameItem {
	public:
		/** Tiki Constructor
			@param QPixmap* picture of a tiki
			@param int nx x value of the tiki's location
			@param int ny y value of the tiki's location*/
		Tiki(QPixmap* p, int nx, int ny);
		/** move function for the tiki  */
		void move();
		/** function to get the location of the mermaid */
		void setGoals(long double wx, long double wy, int c);
};

#endif


