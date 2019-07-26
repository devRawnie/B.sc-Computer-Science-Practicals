#include<iostream>
using namespace std;
int raiseAtoB(int a, int b)
{
	if(b==0)
		return 1;
	else if(b==1)
		return a;
	else
		return a*raiseAtoB(a,b-1);
}
int main()
{
	int b, r;
	cout<<"\nEnter the value of base: ";
	cin>>b;
	cout<<"\nEnter the value of exponent: ";
	cin>>r;
	cout<<b<<" ^ "<<r<<" is: "<<raiseAtoB(b,r);
	
	return 0;
}
