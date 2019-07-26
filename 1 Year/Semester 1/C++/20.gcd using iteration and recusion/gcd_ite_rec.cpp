#include <iostream>
using namespace std;
int gcd_loop(int,int);
int gcd_rec(int , int );

int main()
{
    int no1, no2,ch,gcd;

    cout << "Enter no 1:  ";
    cin >> no1;
	cout<<"\n Enter no 2: ";
	cin>> no2;
    cout<<"Choose from the following\n";
    cout<<"1. Using iteration\n";
    cout<<"2. Using recursion\n";
	cin>>ch;
	switch(ch)
	{
		case 1: gcd = gcd_loop(no1,no2);
				 cout << "G.C.D of " << no1 << " & " <<  no2 << " is: " << gcd_loop(no1, no2);
			break;
		
		case 2:  cout << "G.C.D of " << no1 << " & " <<  no2 << " is: " << gcd_rec(no1, no2);
				break;
		default: cout<<"wrong choice";		 
			
	}

return 0;
}
int gcd_loop(int n1,int n2)
{
    while(n1 != n2)
    {
        if(n1 > n2)
            n1 = n1 - n2;
        else
            n2 = n2 - n1;
    }
return n1;
}


int gcd_rec(int n1, int n2)
{
    if (n2 != 0)
       return gcd_rec(n2, n1 % n2);
    else 
       return n1;
}
