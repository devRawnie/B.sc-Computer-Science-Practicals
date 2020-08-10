#ifndef _POINT_H
#define _POINT_H
#include<iostream>
#include<cstdio>
using namespace std;
template <typename T>
class point{
	public: 
		T x, y;
		point(){
			x = y = 0;
		}
		point(T x, T y){
			this->x = x;
			this->y = y;
		}
		void enterPoint(bool print=false){
			cout<<"\nX co-ordinate: ";
			cin>>x;
			cout<<"\nY co-ordinate: ";
			cin>>y;
			if(print) printPoint();	
		}
		void setPoint(T x, T y){
			this->x = x;
			this->y = y;
		}
		void printPoint(){
			cout<<"(x, y) : ("<<x<<", "<<y<<")\n";
		}
		void printForMatrix(){
			cout<<"\n[ "<<x<<" "<<y<<" ]";			
		}
};

#endif
