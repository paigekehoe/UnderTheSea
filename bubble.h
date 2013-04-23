#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Bubble: public GameItem {
	public:
		Bubble(QPixmap *pm, int x, int y);
		~Bubble();
		void move();
	//public signals:
		//void powerUp();

};
