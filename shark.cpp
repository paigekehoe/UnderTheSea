#include "shark.h"
#include <cmath>
#include <iostream>

Shark::Shark(QPixmap *pm, long double xl, long double yl, int gx, int gy): GameItem(pm, xl, yl){//: QGraphicsPixmapItem(){
	goalX=gx;
	goalY=gy+25;
	x=xl;
	y=yl;
	isBubble=false;
	isShark=true;
	dx=(goalX-x);
	dy=(goalY-y);
	vX=(dx/300.000);
	vY=(dy/300.000);
	std:: cout << "starting y: " << y << std::endl;
	std:: cout << "starting x: " << x << std::endl;
	std::cout << "vY: " << vY << std::endl;
	std::cout << "vX: " << vX << std::endl;
}

Shark::~Shark(){
}

void Shark::move(){
	//int hyp; //= sqrt(
		//vY=velocity*(abs(y-goalY)
		//vX=velocity*cos(t);
	if(y>goalY){
		std::cout<< " you are above me" << std::endl;
		//hyp=sqrt(pow((x-50),2)+pow((y-goalY),2));
		//vX=velocity;
		//vY=velocity*sin(x/y);//(y-goalY)/hyp;
		setPos(x+vX, y-vY);
		x+=vX;
		y-=vY;
	}
	if (y<goalY){
		std::cout <<"you are below me" << std::endl;
		//hyp=sqrt(pow((x-50),2)+pow((y-goalY),2));
		//vX=velocity;
		//vY=velocity*sin(x/y);//(goalY-y)/hyp;
		//y=((goalY-y)/(goalX-x))*(x-vX)+goalY;
		setPos(x+vX, y+vY);
		x+=vX;
		y+=vY;
	} 
	if(y==goalY){
		std::cout << "I don't even know" << std::endl;
	//vX=velocity;
	setPos(x+vX, y);
	x+=vX;
	//y+=vY;

	}
	std::cout << "goaly: " << goalY << std::endl;
	std::cout << "y: " << y <<std::endl;
	/*else i(y=goalY){
		setPos(x-vX, y+vY);
		x-=vX;
		y+=vY;
		} /*
		int r = rand()%2;
		switch(r){
			case 0: 
				setPos(x-vX, y+vY);
				x-=vX;
				y+=vY;
				break;
			case 1:
				setPos(x-vX, y-vY);
				x-=vX;
				y-=vY;
				break;
			case 2:
				setPos(x-vX, y);
				x-=vX;
				break;
			}*/
	
	
	///velocity == number incremented by
	//increment dunction adding velocity to respective x and y

}

void Shark::setVel(int v){
//	vX=vX*v;
//	vY=vY*v;

}

void Shark::setGoals(long double wx, long double wy){
	goalX=wx;
	goalY=wy+25;
	dx=(goalX-x);
	dy=(goalY-y);
	vX=(dx/300.000);
	vY=(dy/300.000);
	std::cout<< "new goals: " << goalY << " " << goalX << std::endl;
	

}

