/*
	Name: 
	Copyright: 
	Author: rohit sharma , rakesh kumar
	Date: 27/02/18 10:19
	Description: 
*/
#include<iostream>
#include<conio.h>
using namespace std;
void perm(int A[], int n,int b )
{
	int temp;
	if(b==(n-1))
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[j];
		}
		cout<<endl;
	}
else{
	for(int i=0;i<n;i++)
	{
		temp = A[i];
		A[i] = A[b];
		A[b] = temp;
		perm(A,n,b+1);
		temp = A[b];
		A[b] = A[i];
		A[i] = temp;
	}
}
}
void perm_rep(int A[],int B[], int n, int b)
{
	if(b==n)
	{
			for(int j=0;j<n;j++)
		{
			cout<<B[j];
		}
		cout<<endl;
	}
else{
	
	for(int i=0;i<n;i++)
	{
		B[b] = A[i];
		perm_rep(A,B,n,b+1);
	}
}
}
int main()
{
	static int n;
	int b=0,ch;
	cout<<"Enter the no of elements:\n->";
	cin>>n;
	int A[n], B[n];
	cout<<"Enter the elements of the array:";
	for(int i=0;i<n;i++)
	{
		cout<<"\n->";
		cin>>A[i];
	}
	cout<<"\nEnter your choice:\n";
	cout<<"1. Permutation with repetition\n";
	cout<<"2. Permuatation without repetition\n";
	cin>>ch;
	switch(ch)
	{
		case 1: perm(A,n,b);
				break;
		case 2: perm_rep(A,B,n,b);
				break;
		default: cout<<"wrong choice!";

	}
	
	return 0;
}
