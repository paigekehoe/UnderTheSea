#ifndef FIRE_H
#define FIRE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Fire: public GameItem {
	public:
		Fire(QPixmap* pm, int x, int y, int gy);
		~Fire();
		void move();
		void setVel(int cx, int cy);
		//mermaid's loc
		int goalY;
		int m;
};

#endif

