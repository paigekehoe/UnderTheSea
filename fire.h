#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include "gameitem.h"

class Fire: public GameItem {
	public:
		Fire(QPixmap* pm, int x, int y);
		~Fire();
		void move();
};


