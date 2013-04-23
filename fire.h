#ifndef FIRE_H
#define FIRE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Fire: public GameItem {
	public:
		Fire(QPixmap* pm, int x, int y, int gx, int gy);
		~Fire();
		void move();
		void setVel();
		//mermaid's loc
		int goalX;
		int goalY;
};

#endif

