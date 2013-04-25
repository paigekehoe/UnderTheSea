#include "boat.h"
Boat::Boat(QPixmap *pm, int x, int y): GameItem(pm, x, y){

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
