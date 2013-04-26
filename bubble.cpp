#include "bubble.h"

Bubble::Bubble(QPixmap *pm, int nx, int ny): GameItem(pm, nx, ny) {
	origin=ny;
	isBubble=true;
	isShark=false;
	move_num=0;
}

void Bubble::move(){
	if(move_num<100){
		setPos(x-vX, y-vY);
		x=x-vX;
		y=y-vY;
		move_num++;
		}
	else{
		setPos(x-vX, y+vY);
		x=x-vX;
		y=y+vY;
		if(move_num>200){
			move_num=0;
		}
	}
}

void Bubble::setVel(int cx, int cy){
	vX=cx;
	vY=cy;
}

void Bubble::setGoals(long double wx, long double wy){
	//do nada
}
