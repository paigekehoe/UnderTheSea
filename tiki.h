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
		x_;
		y_;
};


