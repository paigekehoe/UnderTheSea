#include "boat.h"
Boat::Boat(): QGraphicsPixmapItem(){
	const QPixmap pix("hull.png");
	setPixmap(pix);
}

Boat::~Boat(){

}
