#include "fire.h"

Fire::Fire(QPixmap *pm, int x, int y, int gy): GameItem(pm, x, y){
	goalY = gy;
	m=(gy-y)/(50-x);
	isBubble=false;
	isShark=false;
	// do some calcs to figure out trackign!
}

Fire::~Fire(){

}

void Fire::move(){
	y=(-(m*(x-vX)+goalY));
	x-=vX;
}

void Fire::setVel(int cx, int cy){
	vX=cx;
	vY=cy;


}
