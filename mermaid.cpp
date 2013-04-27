#include "mermaid.h"

Mermaid::Mermaid(): QGraphicsPixmapItem(){ 
	const QPixmap pix("mermaid_real.png");
	setPixmap(pix);
	setPos(50, 175);
	y_=175;
	setFlag(QGraphicsItem::ItemIsFocusable);
	//this lets the object catch keypresses!
}


Mermaid::~Mermaid(){

}

void Mermaid::keyPressEvent(QKeyEvent *k){
	switch(k->key()){
		case Qt::Key_Up:
			if(y_<50){
				return;
			}
			moveUp();
			break;
		case Qt::Key_Down:
			if(y_>380){
				return;
			}
			moveDown();
			break;
	}
}
void Mermaid::moveUp(){
			setPos(50, y_-9);
			y_-=9;
}

void Mermaid::moveDown(){
			setPos(50, y_+9);
			y_+=9;
}
