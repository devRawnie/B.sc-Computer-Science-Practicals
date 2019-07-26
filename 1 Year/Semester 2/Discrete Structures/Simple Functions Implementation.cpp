#include<iostream>
#include<conio.h>
using namespace std;
class Functions{
private: int sum, n;
public:
	Functions(){
		sum =0;
	}
	void getN()
	{
		cout<<"Enter the value of N to calculate R(n):\n";
	cin>>n;		
	}
	void calcR1()
	{
		int store = R1(n);
		cout<<"R1("<<n<<"): "<<store;
	}
	 void calcR2()
	{
		int store = R2(n);
		cout<<"R2("<<n<<"): "<<store;
	
	}
	void calcR3()
	{
		int store = R3(n);
		cout<<"R3("<<n<<"): "<<store;
	
	}

	void start()
	{
		int c;
		getN();
		cout<<"\nChoose from the following options: ";
		cout<<"\n1.R1(n): r1(n-1) + n ";
		cout<<"\n2.R2(n): r2(n-1)+(n*n) ";
		cout<<"\n3.R3(n): 2*r3(n/2)+n "<<endl;
    	cout<<"->";
		cin>>c;
	switch(c)
	{
		case 1: calcR1();
				break;
		case 2: calcR2();
				break;
		case 3: calcR3();
				break;
		default : cout<<"WRONG CHOICE!";
	}
}
int R1(int n)
{
	if(n==1)
		return 1;
	else
		{
		return (R1(n-1)+n);
		}
}
int R2(int n)
{	
	if(n==1)
		return 1;
	else
		{
		return (R2(n-1)+(n*n));
		}
}
int R3(int n)
{
	if(n==0)
		return 1;
	else
		{
		return  2*R3(n/2)+n;
		}
		
}};
int main()
{
	Functions f1;
	f1.start();
	return 0;
	}
