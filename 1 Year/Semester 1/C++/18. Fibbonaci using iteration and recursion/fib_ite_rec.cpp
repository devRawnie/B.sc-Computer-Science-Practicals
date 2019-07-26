#include<iostream>
 
using namespace std;
void fib_rec(int);
 int fibonacci(int);
 
int main()
{
    int no,ch,i=0;
    cout<<"Input the number of terms for Fibonacci Series:";
    cin>>no;
    cout<<"Choose from the following\n";
    cout<<"1. Using iteration\n";
    cout<<"2. Using recursion";
	cin>>ch;
	switch(ch)
	{
		case 1: fib_rec(no);
			break;
		
		case 2:cout<<" Fibonacci series is as follows: ";
			
				while(i<no)
			    {
			        cout<<" "<<fibonacci(i);
			        i++;
			    }
				break;
		
		default: cout<<"wrong choice";		 
			
	}
    
    return 0;
}
void fib_rec(int n)
{
    int  t1 = 0, t2 = 1, nextTerm = 0;

    
    cout << "Fibonacci Series is as follows: ";
    for (int i = 1; i <= n; ++i)
    {
        // Prints the first two terms.
        if(i == 1)
        {
            cout << " " << t1<<" ";
            continue;
        }
        if(i == 2)
        {
            cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << " ";
    }
  }

int fibonacci(int n)
{
    if((n==1)||(n==0))
    {
        return(n);
    }
    else
    {
        return(fibonacci(n-1)+fibonacci(n-2));
    }
}

