#include "bubble.h"
#include <iostream>
#include <cmath> 

Bubble::Bubble(QPixmap *pm, int nx, int ny): GameItem(pm, nx, ny) {
	origin=ny;
	isBubble=true;
	isShark=false;
	move_num=0;
}

void Bubble::move(){
	if(move_num<20){
		setPos(x-vX, y-vY);
		x=x-vX;
		y=y-vY;
		move_num++;
		}
	else{
		setPos(x-vX, y+vY);
		x=x-vX;
		y=y+vY;
		move_num++;
		if(move_num==40){
			move_num=0;
		}
	}
}

void Bubble::setVel(int cx, int cy){
	vX=cx;
	vY=cy;
}

void Bubble::setGoals(long double wx, long double wy, int c){
	int waste = wx+wy+c;
	sqrt(waste);
	//we don't want this function to do anything because bubled dgaf about the mermaid
}
