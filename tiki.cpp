#include "tiki.h"
#include <cmath>

Tiki::Tiki(QPixmap *p, int nx, int ny): GameItem(p, nx, ny){
	isBubble=false;
	isShark=false;
}

void Tiki::move(){
	//tiki does not move!
}

void Tiki::setGoals(long double wx, long double wy, int c){
			int waste = wx+wy+c;
			sqrt(waste);
			//do nothing because Tiki does not care
}
