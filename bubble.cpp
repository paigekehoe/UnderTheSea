#include "bubble.h"

Bubble::Bubble(QPixmap *pm, int x, int y): GameItem(p, x, y) {
	origin =y;
}

~Bubble::~Bubble(){

}

void Bubble::move(){
	if(y>origin+100||y>500){
		setPos(x-vX, y-vY);
		x=x-vX;
		y=y-vY;
		}
	else if(y<origin-100||y==0){
		setPos(x-vX, y+vY);
		x=x-vX;
		y=y+vY;
	}
}

void Bubble::setVel(int cx, int cy){
	vX=cx;
	vY=cy;
}
