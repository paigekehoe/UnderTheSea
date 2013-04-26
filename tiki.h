#ifndef TIKI_H
#define TIKI_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Tiki: public GameItem {
	public:
		Tiki(QPixmap* p, int nx, int ny);
		void move();
		void setGoals(long double wx, long double wy, int c);
};

#endif


