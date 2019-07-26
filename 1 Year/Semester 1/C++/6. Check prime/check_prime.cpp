#include<iostream>
using namespace std;
int check_prime(int);
int main()
{
	int no;
	void print_prime();
	cout<<"Enter any no:";
	cin>>no;
	if(check_prime(no))
	{
		cout<<"\nThe given no is a prime no\n";
	}
	else
	{
		cout<<"\nThe given no is not a prime no\n";
	}
	print_prime();
	return 0;
}
void print_prime( )
{
 int n = 2;
 while(n<100)
 {
 	if(check_prime(n))
 	{cout<<n<<endl;

	 }
n++;
 }
}
int check_prime(int x)
{
	int flag = 1,n=2,ch=x/2;
	while(n<=ch)
	{
		if(x%n==0)
		{
			flag = 0;
			break;
		}
	n++;	
	}
if(flag)
{
	return 1;
}
else
{
	return 0;
}
}
