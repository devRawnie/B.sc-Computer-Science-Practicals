#ifndef _COHEN_SUTHERLAND_
#define _COHEN_SUTHERLAND_
#include<iostream>
#include "point.h"

using namespace std;

const int INSIDE = 0;	//0000
const int LEFT = 1;		//0001
const int RIGHT = 2;	//0010
const int BOTTOM = 4;	//0100
const int TOP = 8;		//1000

class line_clipping{
	private: 	point<int> p1, p2;
				int l, t, r, b;
	int generateOutcode(point<int> p){
		int outcode = INSIDE;
		if(p.x < l)
			outcode |= LEFT;
		else if(p.x > r)
			outcode |= RIGHT;
		if(p.y < b)
			outcode |= BOTTOM;
		else if(p.y > t)
			outcode |= TOP;
		return outcode;
	}
	
	public:
		line_clipping(){
			cout<<"\n******LINE CLIPPING******\n";
			// l = b = 50;
			// r = t = 100;	
			r = t = 400;
			l = b = 200;
		}
		line_clipping(point<int> top, point<int> bottom){
			l = top.x;
			t = top.y;
			r = bottom.x;			
			b = bottom.y;	
		}
		void getCoordinates(){
			cout<<"\nEnter First point";
			p1.enterPoint();
			cout<<"\nEnter Second point";
			p2.enterPoint();	

		}
		
		void plotline(){
			int o1 = generateOutcode(p1);
			int o2 = generateOutcode(p2);
			bool accept = false;
			while(true){
				if(o1 == 0 && o2 == 0){
					accept = true;
					break;
				}else if(o1 & o2){
					break;
				}else{
					int otemp;
					point<int> temp;
					otemp = o1 != 0? o1 : o2;
					if(otemp & TOP){
						temp.x = p1.x + (p2.x - p1.x)*(t - p1.y) / (p2.y - p1.y);
						temp.y = t;
					}else if(otemp & BOTTOM){
						temp.x = p1.x + (p2.x - p1.x)*(b - p1.y) / (p2.y - p1.y);
						temp.y = b;
					}else if(otemp & LEFT){
						temp.y = p1.y + (p2.y - p1.y)*(l - p1.x) / (p2.x - p1.x);
						temp.x = l;
					}else if(otemp & RIGHT){
						temp.y = p1.y + (p2.y - p1.y)*(r - p1.x) / (p2.x - p1.x);
						temp.x = r;
					}


					if(otemp == o1){
						p1.x = temp.x;
						p1.y = temp.y;
						o1 = generateOutcode(p1);
					}else{
						p2.x = temp.x;
						p2.y = temp.y;
						o2 = generateOutcode(p2);
					}
				
				
				}
			}
			
			if(accept){ 
				setcolor(GREEN);
				printf("Line accepted from (%d,%d) to (%d,%d)",p1.x,p1.y,p2.x,p2.y);
				// line(p1.x, p1.y, p2.x, p2.y);
			}else{
				setcolor(RED);
				printf("Line rejected from (%d,%d) to (%d,%d)",p1.x,p1.y,p2.x,p2.y);
				// line(p1.x, p1.y, p2.x, p2.y);
			}
		}
		
};


void execute_line_clipping(){
	line_clipping ob;
	ob.getCoordinates();
	ob.plotline();
}

#endif
