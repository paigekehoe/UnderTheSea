#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <iostream>

class Mermaid: public QGraphicsPixmapItem {
	public:
		Mermaid();
		~Mermaid();
		qreal y_;
		void keyPressEvent(QKeyEvent *k);
	public slots:
		void moveUp();
		void moveDown();
};
