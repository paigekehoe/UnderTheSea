#include "tiki.h"

Tiki::Tiki(): QGraphicsPixmapItem(){
	const QPixmap pix("tiki.png");
	setPixmap(pix);
	
}
