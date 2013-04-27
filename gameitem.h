#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
/** partially virtual base class inheriting from QGraphicsPixmapItem for all of the moving items in the game. Has a pure virtual move() function
* and a pure virtual setGoals() function.  Also holds variables for velocity, location, and QPixmaps 
* @author Paige Kehoe */
class GameItem: public QGraphicsPixmapItem {
	public:
		/** Game constructor
		* @param QPixmap* a pointer to a picture of the item
		* @param int nx starting x location
		* @param int ny starting y location*/
		GameItem(QPixmap *pm, int nx, int ny): QGraphicsPixmapItem(){
			pixMap=pm;
			setPixmap(*pm);
			x=nx;
			y=ny;
			setPos(nx,ny);
		};
		/** pure virtual function for the movement of an object*/
		virtual void move() = 0;
		/** boolean to return true if on screen and false if off screen*/
		bool onScreen(){
			if(x<=0){
				return false;
			}
			else
				return true;
		};
		/** boolean to tell if derived object is of the Bubble class*/
		bool isBubble;
		/** boolean to tell if derived object is of the Shark class*/
		bool isShark;
		/** virtual function to get location of the mermaid */
		virtual void setGoals(long double wx, long double wy, int c)=0;
	protected:
		/** x value of location */
		int x;
		/** goal x - mermaids x value location */
		long double goalX;
		/**  goal for y - mermaid's y value location */
		long double goalY;
		/** y value of location */
		int y;
		/** velocity for x */
		long double vX;
		/** velocity for y */
		long double vY;
		/** pointer to the picture for the object */
		QPixmap *pixMap;
		
};

#endif
