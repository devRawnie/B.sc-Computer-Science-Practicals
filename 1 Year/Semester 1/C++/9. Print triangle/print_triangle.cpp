#include<iostream>
using namespace std;
int main()
{
	int side;
	void draw(int);
	cout<<"Enter side of triangle: ";
	cin>>side;
	draw(side);
	return 0;
	
}
void draw(int x)
{
	int i,j,k;
	char c = '^';
	for(i=0;i<x;i++)
	{
		for(j=x;j>i;j--)
		{
			cout<<" ";
		}
	for(k=0;k<2*i+1;k++)
	{
		cout<<"*";
	}
	cout<<"\n";
	}
	
}
