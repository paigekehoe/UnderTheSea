#ifndef SHARK_H
#define SHARK_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Shark: public GameItem {
	public:
		Shark(QPixmap *pm, long double xl, long double yl, int gx, int gy);
		~Shark();
		void move();
		void setVel(int v);
		int velocity;		
		void setGoals(long double wx, long double wy, int c);
		long double dx, dy;
		long double x;
		long double y;
};

#endif
