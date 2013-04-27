#include "shark.h"
#include <cmath>
#include <iostream>

Shark::Shark(QPixmap *pm, long double xl, long double yl, int gx, int gy): GameItem(pm, xl, yl){//: QGraphicsPixmapItem(){
	goalX=gx;
	goalY=gy+25;
	x=xl;
	y=yl;
	isBubble=false;
	isShark=true;
}

Shark::~Shark(){
}

void Shark::move(){
	if(y>goalY){ //below mermaid
		setPos(x-vX, y-vY);
		x-=vX;
		y-=vY;
	}
	if (y<goalY){//above mermaid
		setPos(x-vX, y+vY);
		x-=vX;
		y+=vY;
	} 
	if(y==goalY){ // right on track
		setPos(x-vX, y-(vY/2));
		x-=vX;
		y-=vY;
	}
}

void Shark::setVel(int v){
	vX=v;
	vY=v;

}

void Shark::setGoals(long double wx, long double wy, int c){
	if(c%200==0){ //only update every 200 timeout() s
		goalX=wx;
		goalY=wy+25;}
}

