#include<iostream>
using namespace std;
int main()
{
	int no;
	void cal(int);
	cout<<"enter the value of n: ";
	cin>>no;
	cal(no);
	return 0;
}
void cal(int n)
{
	
	float sum=0,i=1;
	while(i<=n)
	{
		sum += 1/i;
		i++;
	}
cout<<"Sum upto "<<n<<" terms is: "<<sum;
}
