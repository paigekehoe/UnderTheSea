#ifndef TIKI_H
#define TIKI_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Tiki: public GameItem {
	public:
		Tiki(QPixmap* pm, int x, int y);
		~Tiki();
		void move();
		int x_;
		int y_; // to be used from fire
};

#endif


