#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Shark: public GameItem {
	public:
		Shark(QPixmap *pm, int x, int y);
		~Shark();
		void move();
		void setVel(int cx, int cy);
};
