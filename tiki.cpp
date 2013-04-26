#include "tiki.h"

Tiki::Tiki(QPixmap *p, int nx, int ny): GameItem(p, nx, ny){
	isBubble=false;
	
}


void Tiki::move(){
	//tiki does not move!
}

void Tiki::setGoals(long double wx, long double wy, int c){
	
}
