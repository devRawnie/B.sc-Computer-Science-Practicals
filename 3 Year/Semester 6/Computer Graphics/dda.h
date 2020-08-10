#ifndef _DDA_H
#define _DDA_H
#include<iostream>
#include "point.h"
#include<cmath>
using namespace std;

class dda{
	private: 	point<float> p1, p2;
				float dx, dy, steps;
	void calcuateSteps(point<float> p1, point<float> p2){
		dx = fabs(p1.x - p2.x);
		dy = fabs(p1.y - p2.y);
		steps = max(dx, dy);
	}
	
	public: 
	
	dda(){
	}
	
	//enter the coordinates of two points
	void getCoordinates(){
		cout<<"\nEnter First point";
		p1.enterPoint();
		cout<<"\nEnter Second point";
		p2.enterPoint();	
		calcuateSteps(p1, p2);
	}
	void draw(){
		float xInc = 	dx / steps;
		float yInc = 	dy / steps;	
		float X = p1.x;
		float Y = p1.y;
		for(int i = 0; i <= steps; i++){
			// putpixel(X, Y, 7);
			
			printf("(%d,%d)\n",(int)X,(int)Y);
			X += xInc;
			Y += yInc;
		}
	}
	
};
void execute_dda(){
	dda ob;
	ob.getCoordinates();

	ob.draw();

}
#endif

