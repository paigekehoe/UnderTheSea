#include "shark.h"

Shark::Shark(QPixmap *pm, int x, int y, int gx, int gy): GameItem(pm, x, y){//: QGraphicsPixmapItem(){
	goalX=gx;
	goalY=gy;
}

Shark::~Shark(){
}

void Shark::move(){
	if(y>goalY){
		setPos(x-vX, y-vY);
		x-=vX;
		y-=vY;
	}
	else if (y<goalY){
		setPos(x-vX, y+vY);
		x-=vX;
		y+=vY;
	} ///velocity == number incremented by
	//increment dunction adding velocity to respective x and y

}

void Shark::setVel(int cx, int cy){
	vY=cy;
	vX=cx;

}

void Shark::setGoals(int wx, int wy){
	goalX=wx;
	goalY=wy;

}
