#ifndef FIRE_H
#define FIRE_H
#define PI 3.14159265

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QtGlobal>
#include <cmath>
#include "gameitem.h"
/* A class that inherits from GameItem to create a QGraphicsPixmapItem that is a ball of fire.
* balls of fire shoot at the player as it moves across the screen 
* @author Paige Keoe*/
class Fire: public GameItem {
	public:
		/** Fire constructor
		* @param QPixmap* a pointer to a picture of a fire ball
		* @param int nx starting x location
		* @param int ny starting y location*/
		Fire(QPixmap* pm, long double xl, long double yl, int gy);
		/** Fire destructor */
		~Fire();
		/** a function to shoot fireballs at the mermaid */
		void move();
		/** a funciton to set the velocity of the fireballs*/
		void setVel(double cx, double cy);
		/** variable for the location of the mermaid */
		long double goalY;
		/** variable for the x value location of the fireball */
		long double x;
		/** a varaible for the y value locaiton of the fireball*/
		long double y;
		/** funciton to get the location of the mermaid and update it for the fireballs*/
		void setGoals(long double wx, long double wy, int c);
};

#endif

