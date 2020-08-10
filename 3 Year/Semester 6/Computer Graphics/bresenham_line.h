#ifndef _BRESENHAM_LINE_H
#define _BRESENHAM_LINE_H

#include<iostream>
#include<graphics.h>
#include "point.h"
using namespace std;



class bresenham{
	private: 	point<int> p1, p2;	
				int dx, dy,t;
	public: 
	bresenham(int thick){
		p1.setPoint(50,50);
		p2.setPoint(200,200);
		t = thick;
		dx = p2.x - p1.x;
		dy = p2.y - p1.y;	
	}
	void plot(int x,int y){
		int i = 0;
		while(i<t){
			putpixel(x+i,y,RED);
			i++;
		}
	}
	//enter the coordinates of two points
	void getCoordinates(){
		cout<<"\nEnter First point";
		p1.enterPoint();
		cout<<"\nEnter Second point";
		p2.enterPoint();
		cout<<"\nEnter thickness";
		dx = p2.x - p1.x;
		dy = p2.y - p1.y;		
	}
	void drawline(){
		int d = 2*dy - dx;
		int x = p1.x;
		int y = p1.y;
		plot(x,y);
		while(x <= p2.x){
			// printf("(%d,%d)\n",x,y);
			if(d>0){
				d += 2*(dy - dx);
				y++;
			}else{
				d += 2*dy;
			}
			x++;
			plot(x,y);
		}	
	}
	
};
void execute_b(){
	bresenham ob(10);
	// ob.getCoordinates();
	int gd = DETECT, gm;
	initgraph(&gd,&gm,NULL);
	ob.drawline();

	getch();
	closegraph();

}

#endif
