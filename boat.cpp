#include "boat.h"
Boat::Boat(QPixmap *pm, int x, int y): GameItem(pm, x, y){
	isBubble=false;
	isShark=false;
}

Boat::~Boat(){

}

void Boat::move(){
	setPos(x-vX, y);
	x=x-vX;
}

void Boat::setVel(int cx){
	vX=cx;
}

bool Boat::onScreen(){
	if(x<-50){
		return false;
	}
	return true;
}
