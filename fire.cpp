#include "fire.h"
#include <iostream>

Fire::Fire(QPixmap *pm, long double xl, long double yl, int gy): GameItem(pm, xl, yl){
	goalY = gy+25;
	m=(y-gy)/(x-50);
	isBubble=false;
	isShark=false;
	x=xl;
	y=yl;
	long double dy = (goalY-y);
	long double dx =(50.00000-x);
	vX=(dx/250.00000);
	vY=(dy/250.00000);
	//std::cout << "vY: " << vY << std::endl;
	//std::cout << "vX: " << vX << std::endl;
	
}

Fire::~Fire(){

}

void Fire::move(){
	setPos(x+vX, y+vY);
	//std::cout << "x: " << x << std::endl;
	//std::cout << "y: " << y <<std::endl;
	x+=vX;
	y+=vY;
}

void Fire::setVel(double cx, double cy){
	//vX=vX*cx;
	//vY=vY*cy;
	
	//speed = cx;
}

void Fire::setGoals(long double wx, long double wy, int c){
	//do nothing because we do not want to change fire's goal
}
