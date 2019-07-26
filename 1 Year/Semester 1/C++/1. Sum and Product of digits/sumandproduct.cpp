#include<iostream>
using namespace std;

int main()
{
	int no; 
	cout<<"Enter any no";
	cin>>no;
		void cal_sum(int);
	void cal_pro(int);
	cal_sum(no);
	cal_pro(no);		return 0;
}

void cal_sum(int x)
{
	int sum=0,ten,n;
	while(x%10!=0)
	{
		ten = x/10;
		n = x - ten*10;
		sum += n;
		x = x/10;
	}
	
	cout<<"\nSum of digits is: ";
	cout<<sum;
}
void cal_pro(int x)
{
	int pro=1,n,ten;
	while(x%10!=0)
	{
		
		ten = x/10;
		n = x - ten*10;
		pro *= n;
		x = x/10;
	}
	cout<<"\nProduct of digits is: ";
	cout<<pro;
}
