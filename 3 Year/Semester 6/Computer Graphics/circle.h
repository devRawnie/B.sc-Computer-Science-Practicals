#ifndef _CIRCLE_H
#define _CIRCLE_H
#include<iostream>
using namespace std;

class Circle{
    private: int X,Y,radius;
        void plot(int x, int y){
            printf("(%d,%d)\n",x,y);
        }
        void getValues(){
            cout<<"\nEnter radius of the circle:\n";
            cin>>radius;
            cout<<"Enter center of the circle:\n";
            cout<<"x: ";
            cin>>X;
            cout<<"y: ";
            cin>>Y;
        }
    public:
        Circle(){}

        void plot(){
            getValues();
            int x = 0, y=radius,dx;
            int d = 1 - radius;
            plot(x,y);
            while(y > x){
                // cout<<"d: "<<d<<endl;
                if(d < 0){
                    dx = 2*x + 3;
                    // cout<<"dx: "<<dx<<endl;

                }else{
                    dx = 2*(x-y)+5; 
                    y--;
                }
                x++;
                d += dx;
                plot(x,y);
            }
        }
};


void execute_circle(){
    Circle c;
    c.plot();
}


#endif