#ifndef BUBBLE_H
#define BUBBLE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Bubble: public GameItem {
	public:
		Bubble(QPixmap *pm, int nx, int ny);
		void move();
		int origin;
		void setVel(int cx, int cy);
	//public signals:
		//void powerUp();

};

#endif
