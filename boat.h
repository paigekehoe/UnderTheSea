#ifndef BOAT_H
#define BOAT_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Boat: public GameItem{
	public:
		Boat(QPixmap *pm, int x, int y);
		~Boat();
		void move();
		void setVel(int cx);
};

#endif
