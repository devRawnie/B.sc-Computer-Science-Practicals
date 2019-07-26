#include<iostream>
using namespace std;
void modify(int&,int&);
int main()
{
	int n1,n2;
	cout<<"Enter the value of First number: ";
	cin>>n1;
	cout<<"Enter the value of Second number: ";
	cin>>n2;
	modify(n1,n2); //multiplies first number with 2 and second no with 3
	cout<<"VALUES OF FIRST AND SECOND NUMBER IN MAIN: "<<n1<<" , "<<n2<<"\n";
	return 0;
}
void modify(int &x, int &y)
{
	x = x*2;
	y = y*3;
	
	cout<<"VALUES OF FIRST AND SECOND NUMBER IN FUNCTION: "<<x<<" , "<<y<<endl;
}
