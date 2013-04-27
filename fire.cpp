#include "fire.h"
#include <iostream>

Fire::Fire(QPixmap *pm, long double xl, long double yl, int gy): GameItem(pm, xl, yl){
	goalY = gy+25;
	isBubble=false;
	isShark=false;
	x=xl;
	y=yl;
	long double dy = (goalY-y);
	long double dx =(50.00000-x);
	vX=(dx/250.00000);
	vY=(dy/250.00000);
	
}

Fire::~Fire(){

}

void Fire::move(){
	setPos(x+vX, y+vY);
	x+=vX;
	y+=vY;
}

void Fire::setVel(double cx, double cy){
	vX=vX*cx;
	vY=vY*cy;

}

void Fire::setGoals(long double wx, long double wy, int c){
	//do nothing because we do not want to change fire's goal
		int waste = wx+wy+c;
		sqrt(waste);
}
