/*
	Name: PERMUTATION AND COMBINATION
	Copyright: 
	Author: ROHIT SHARMA RAKESH KUMAR
	Date: 06/04/18 13:43
	Description: 
*/
#include<iostream>
#include<conio.h>
using namespace std;
int ncr(int n, int r)
{
	if(r>n)
		return 0;
	else if(r==0||n==0||r==n)
		return 1;
	else
		return (ncr(n-1,r-1) + ncr(n-1,r));
	
}
int npr(int n, int r)
{
	if(r>n)
		return 0;
	else if(r==0)
		return 1;
	else
		return (n*npr(n-1,r-1));
	
}
void findPermutation(int n, int r)
{
	int P = npr(n,r);
	cout<<endl<<"P("<<n<<","<<r<<"): "<<P;
}
void findCombination(int n, int r)
{
	
	int C = ncr(n,r);
	cout<<endl<<"C("<<n<<","<<r<<"): "<<C;
}

int main()
{
	int n, r,ch;
	cout<<"Enter the value of n\n";
	cin>>n;
	cout<<"Enter the value of r\n";
	cin>>r;
	cout<<"Select from the following:\n";
	cout<<"1. Permutation(n,r)\n";
	cout<<"2. Combination(n,r)\n";
	cin>>ch;
	switch(ch)	
	{
		case 1: findPermutation(n,r);
				break;
		case 2: findCombination(n,r);
				break;
		default: cout<<"wrong choice";
	}
	getch();
	return 0;
	}
