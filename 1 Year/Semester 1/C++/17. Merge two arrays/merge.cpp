#include<iostream>
using namespace std;
void merge(int[],int[],int[],int,int);
int main()
{
	int ar1[50], ar2[50], size1, size2, size, i, ar3[100];
	cout<<"Enter Array 1 Size : ";
	cin>>size1;
	cout<<"Enter Array 1 Elements in ascending order : ";
	for(i=0; i<size1; i++)
	{
		cin>>ar1[i];
	}
	cout<<"Enter Array 2 Size : ";
	cin>>size2;
	cout<<"Enter Array 2 Elements in ascending order: ";
	for(i=0; i<size2; i++)
	{
		cin>>ar2[i];
	}
	merge(ar1, ar2, ar3, size1, size2);
size=size1+size2;
	cout<<"Now the new array after merging is :\n";
	for(i=0; i<size; i++)
	{
		cout<<ar3[i]<<" ";
	}
}
void merge(int ar1[],int ar2[],int ar3[],int size1,int size2)
{
	
	int i,j,k;
	
	for(i=0,j=0,k=0;i<size1&&j<size2;)
	{
		if(ar1[i]<ar2[j])
		{
			ar3[k++] = ar1[i++];
		}
		if(ar1[i]>ar2[j])
		{
			ar3[k++] = ar2[j++];
		}
		
	}
if(i<size1)
{		while(i<size1)
		{
			ar3[k++] = ar1[i++];
		}
	}
if(j<size2)
{	while(j<size2)
		{
			ar3[k++] = ar1[j++];
			
			
			}
}	
	
}
