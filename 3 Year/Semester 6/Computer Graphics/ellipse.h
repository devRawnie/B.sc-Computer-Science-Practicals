#ifndef _ELLIPSE_H
#define _ELLIPSE_H
#include<iostream>
using namespace std;

class Ellipse{
    private: int X,Y,major, minor;
        void plot(int x, int y){
            printf("(%d,%d)\n", x, y);
        }

    public:
        Ellipse(){}
        Ellipse(int a,int b){
            major=a;
            minor=b;
        }
        void getValues(){
            cout<<"Enter center of the ellipse:\n";
            cout<<"x: ";
            cin>>X;
            cout<<"y: ";
            cin>>Y;
            cout<<"Enter the length of major-axis: ";
            cin>>major;
            cout<<"Enter the length of minor-axis: ";
            cin>>minor;            
        }
        void plot(){

            int dx, dy, d1, d2, x=0, y=minor;
            
            // dx=2*minor*minor*x;
            dx=0;
            dy=2*major*major*y;

            d1=(int)(minor*minor)+(0.25*major*major)-(major*major*minor);
            // cout<<"d1: "<<d1<<endl;
            
            plot(x,y);
            // in region 1
            while(dx<dy){

                x++;
                dx += 2*minor*minor;

                if(d1<0){	
                    // d1 += (minor*minor)*(3+2*x);	
                    d1 += minor*minor+dx;	
                }
                else{		
                    y--;
                    dy -= 2*major*major;
                    d1 += minor*minor + dx - dy;
                }
                // cout<<"d1: "<<d1<<endl;
                plot(x,y);
            }
            
            //region 2
            d2 = (minor*minor)*(x+0.5)*(x+0.5)+(major*major)*(y-1)*(y-1)-(major*major*minor*minor);
            // cout<<"d2: "<<d2<<endl;             
            while (y >0){ 
                    y--; 
                    dy -= 2 * major * major; 
                if (d2 > 0){ 
                    d2 += major * major - dy; 
                } 
                else{ 
                    x++; 
                    dx += 2 * minor * minor; 
                    d2 +=  major * major + dx - dy; 
                } 
                // cout<<"d2: "<<d2<<endl;
                plot(x,y);
            }

        }
};


void execute_ellipse(){
    // Ellipse e(8,6);
    Ellipse e;
    // e.getValues();
    e.plot();
}


#endif