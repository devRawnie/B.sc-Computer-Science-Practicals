#include<iostream>
#include<conio.h>
using namespace std;
int TOH(int n)
{
	if(n==1)
		return 1;
	else
		return (2*TOH(n-1)+1);
};
void printSum(int n)
{
	int s=0;
	s = TOH(n);
	cout<<n<<" no of discs can be moved onto another tower in "<<s<<" moves.";
}
int main()
{
	int a;
    cout<<"Enter no of discs:\n";
	cin>>a;
	printSum(a);
	return 0;
}
