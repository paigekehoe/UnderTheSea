#include "shark.h"

Shark::Shark(): QGraphicsPixmapItem(){//: QGraphicsPixmapItem(){
	const QPixmap pix("sharky.png");
	setPixmap(pix);
}

Shark::~Shark(){
}
