/*
	Name: 
	Copyright: 
	Author: rohit sharma,rakesh kumar
	Date: 12-04-18 17:24
	Description: 
*/
#include<iostream>
#include<conio.h>
using namespace std;
class Tree{
	private: int m, i,l;
	public: Tree()
	{
		m = i=l=0;
	}
	void getValue()
	{
		cout<<"Enter the value of m in m-ary tree:\n";
		cin>>m;
		cout<<"Enter the value of internal nodes (i): \n";
		cin>>i;
	findValue();
	}
	void findValue()
	{
		l = (m-1)*i + 1;
	}
	void display()
	{
		cout<<"\nFor a m-ary tree with m: "<<m<<" and internal vertices "<<i;
		cout<<" will have "<<l<<" leaves.";
	}
};
int main()
{
	Tree t;
	t.getValue();
	t.display();
	getch();
	return 0;
	
}
