#include<iostream>
using namespace std;
void fac_loop(int);
int fac_rec(int);
int main()
{
	int no,factorial,ch;
	cout<<"Enter any no: ";
	cin>>no;
	cout<<"\nChoose from the following";
	cout<<"\n1.Using iteration";
	cout<<"\n2.Using recursion\n";
	cin>>ch;
	switch(ch)
	{
		case 1: fac_loop(no);
				break;
		case 2: factorial = fac_rec(no);		
				cout<<"\nFactoral of "<<no<<" is "<<factorial;
				break;
		default: cout<<"\nwrong choice";
}
	
	return 0;
}
void fac_loop(int n)
{
	int val=1,i;
	for(i=1;i<=n;i++)
	{
		val = val*i;
		cout<<"\n After iteration "<<i<<" value is: "<<val;
	}
			cout<<"\nFactoral of "<<n<<" is "<<val;

}
int fac_rec(int n)
{
	if(n==1)
	return 1;
	else 
	cout<<"\nThe number now is: "<<n;
	return n*fac_rec(n-1);
}
