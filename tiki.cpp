#include "tiki.h"

Tiki::Tiki(QPixmap *pm, int x, int y): GameItem(p, x, y){
	x_=x;
	y_=y;
	
}

Tiki::~Tiki(){

}

void Tiki::move(){
	//tiki does not move!
}
