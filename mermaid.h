#ifndef MERMAID_H
#define MERMAID_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <iostream>
/* a class that inherits from QGraphicsPixmapItem to create the main player for the game,
* a mermaid.  The mermaid has the ability to move up and down with key press events of the arrow keys
* @author Paige Kehoe */

class Mermaid: public QGraphicsPixmapItem {
	public:
		/** Mermaid constructor */
		Mermaid();
		/** mermaid destructor */
		~Mermaid();
		/** y value of the mermaid's location */
		qreal y_;
		/** overridden keypressevent function to catch the keyboard, check for up and down arrow presses and move the mermaid up or down */
		void keyPressEvent(QKeyEvent *k);
		/** function to move the mermaid up */
		void moveUp();
		/**  function to move the mermaid down */
		void moveDown();
};

#endif
