#include<iostream>
using namespace std;
#define pi 3.14 
class circle
{
	float r;
	float area;
	float circum;
public:
	void takeradius()
	{
		cout<<"Enter the radius of the circle:";
		cin>>r;
	}
	void calculate()
	{
		area = (pi*(r)*(r));
		circum = (2*(pi*r));
	cout<<"Area of the Circle is: "<<area<<endl;
	cout<<"Circum of the Circle is: "<<circum;
	
	}
}c1;
int main()
{	
	c1.takeradius();
	c1.calculate();
	return 0;
}
