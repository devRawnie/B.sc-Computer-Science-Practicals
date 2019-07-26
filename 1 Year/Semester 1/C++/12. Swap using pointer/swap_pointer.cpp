#include<iostream>
using namespace std;
void swap(int *a,int *b)
{	cout<<"error";
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int x, y;
	cout<<"Enter First Number: ";
	cin>>x;	
	cout<<"\n Enter Second Number: ";
	cin>>y; 
	int *n1 = &x,*n2=&y;
	swap(n1,n2);
	cout<<"First no: "<<*(n1);
	cout<<"Second no: "<<*(n2);
	return 0;
}

