#include "bubble.h"

Bubble::Bubble(): QGraphicsPixmapItem(){
	const QPixmap* p("bubble.png");
	setPixmap(p)
}
