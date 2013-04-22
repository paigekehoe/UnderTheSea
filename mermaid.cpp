#include "mermaid.h"

Mermaid::Mermaid(): QGraphicsPixmapItem(){ //30, 175, 50, 50){
	const QPixmap pix("mermaid_real.png");
	setPixmap(pix);
setPos(0, 175);
	y_=175;
	setFlag(QGraphicsItem::ItemIsFocusable);
}


Mermaid::~Mermaid(){

}

void Mermaid::keyPressEvent(QKeyEvent *k){
if(y_<=0){
	y_++;
	return;
}
if(y_>=450){
	y_--;
	return;
}
//std::cout << "key press" << std::endl;
	switch(k->key()){
		case Qt::Key_Up:
			moveUp();
			break;
		case Qt::Key_Down:
			moveDown();
			break;
	}
}
void Mermaid::moveUp(){
			setPos(0, y_-5);
			y_-=5;
}

void Mermaid::moveDown(){
			setPos(0, y_+5);
			y_+=5;
}
