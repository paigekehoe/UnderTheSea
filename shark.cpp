#include "shark.h"

Shark::Shark(QPixmap *pm, int x, int y): GameItem(pm, x, y){//: QGraphicsPixmapItem(){

}

Shark::~Shark(){
}

void Shark::move(){
	setPos(x, y); ///velocity == number incremented by
	//increment dunction adding velocity to respective x and y

}

void Shark::setVel(int cx, int cy){
	y+=vY;
	x+=vX;

}
