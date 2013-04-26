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
		long double origin;
		void setVel(int cx, int cy);
		int move_num;
		void setGoals(long double wx, long double wy, int c);
	//public signals:
		//void powerUp();

};

#endif
