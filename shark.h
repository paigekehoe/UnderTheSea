#ifndef SHARK_H
#define SHARK_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Shark: public GameItem {
	public:
		Shark(QPixmap *pm, int x, int y, int gx, int gy);
		~Shark();
		void move();
		void setVel(int cx, int cy);
		void setGoals(int wx, int wy);
		int goalY;
		int goalX;
};

#endif
