#include<iostream>
#include<conio.h>
using namespace std;
class Fibonacci{
int i;
int sum;
int n;

public:
Fibonacci(){
    i=0;
    n=0;
    sum = 0;
    }
    void enter()
    {
     cout<<"Enter the number of terms for Fibonacci Series: ";
     cin>>n;   
        
        }
        void print(){
            cout<<"Series:\n";
    
	while(i<n)
    { sum += fib(i);
        cout<<fib(i)<<" ";
        i++;
    }
    cout<<"\nThe sum of Fibonacci Series upto "<<n<<" terms is "<< sum;
    
            }
            
int fib(int n)
{
	if(n==1||n==0)
		return n;
	else 
	return (fib(n-1)+fib(n-2));
}
};
int main()
{
    Fibonacci fb;
   fb.enter();
   fb.print();
getch();
	return 0;
}
