#ifndef FIRE_H
#define FIRE_H
#define PI 3.14159265

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include <cmath>
#include "gameitem.h"

class Fire: public GameItem {
	public:
		Fire(QPixmap* pm, long double xl, long double yl, int gy);
		~Fire();
		void move();
		void setVel(double cx, double cy);
		//mermaid's loc
		long double goalY;
		int m;
		int distance;
		long double x;
		long double y;
		
		double speed;
		int angle;
		void setGoals(long double wx, long double wy);
};

#endif

