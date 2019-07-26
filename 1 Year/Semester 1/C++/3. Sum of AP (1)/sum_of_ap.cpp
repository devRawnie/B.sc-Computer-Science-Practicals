#include<iostream>
using namespace std;
int main()
{
	int n;
	void cal(int);
	cout<<"Enter the value of n: ";
	cin>>n;
	cal(n);
	return 0;
}
void cal(int x)
{
	int sum;
	sum = (x*(x+1))/2;
	cout<<"the sum upto n terms is: "<<sum;

}
