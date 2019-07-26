#include<iostream>
using namespace std;
int main()
{
	#define swapn(a,b) int temp; temp = a; a = b; b = temp;
	int no1, no2;
	cout<<"Enter any two numbers: \n";
	cin>>no1>>no2;
	cout<<"BEFORE SWAPPING";
	cout<<"\nFirst Number: "<<no1<<endl;
	cout<<"Second Number: "<<no2<<endl;
	swapn(no1,no2);
	cout<<"AFTER SWAPPING\n";
	cout<<"First Number: "<<no1<<endl;
	cout<<"Second Number: "<<no2<<endl;
	return 0;
}
