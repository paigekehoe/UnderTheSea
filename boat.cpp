#include "boat.h"
#include <cmath>

Boat::Boat(QPixmap *pm, int x, int y): GameItem(pm, x, y){
	isBubble=false;
	isShark=false;
	//a boat is not a bubble or a shark... wow
}

Boat::~Boat(){

}

void Boat::move(){
	setPos(x-vX, y);
	x=x-vX;
	//set pos and update x,y
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

void Boat::setGoals(long double wx, long double wy, int c){
		int waste = wx+wy+c;
		sqrt(waste);
		//we really don't want this to do anything because Boat objects do not care about where the mermaid is

}
