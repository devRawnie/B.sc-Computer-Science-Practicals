/*
	Name: P1 
	Copyright: 
	Author: rohit sharma,Rakesh Kumar
	Date: 09/01/18 09:22
	Description: Implement array as a set, and make a menu driven program which displays cardinality, presence of an element, 
	and power set of the set
	
*/
#include<iostream>
#include<math.h>
using namespace std;
class Set{
	int *arr, size;
	public:
	Set()
	{
		size = 0;
		arr = NULL;
	}
void setsize()
{
	cout<<"\nEnter the size of the array: ";
	cin>>size;
	arr = new int[size];
}
void enter()
{
	cout<<"\nEnter the elements of the Array: \n";
	for(int i =0;i<size;i++)
	{
		cin>>arr[i];
	}
unique();
}
void unique()
{
	int i,j,temp;
		
	for(int i =0;i<size;i++)
	{
		temp = arr[i];
		
			for(int j=1+i;j<size;)
			{
				if(temp==arr[j])
				{
						for(int k=j;k<size;k++)
						{
							arr[k] = arr[k+1];
						}
						size--;	
		}
				else{
					j++;
				}
				
			}
	}
}

void show()
{
		cout<<"\n{ ";
			for(int i=0;i<size;i++)
			{
				cout<<arr[i];
				if(i!=size-1)
				{
					cout<<", ";
				}
			}
		cout<<" }\n";
	}
void ismember(int a)
	{	
	int flag=0;
			for(int i=0;i<size;i++)
			{
				if(arr[i]==a)
					{
						flag=1;
						break;
					}
			}
		if(flag==1)
			{
			cout<<"\nThe element "<<a<<" belongs to the set";
			}
		else
			{
				cout<<"\nThe element "<<a<<" does not belong to the set";
			}
	}
void cardinality()
{
	cout<<"\nCardinality of the set: "<<size;
}
void powerset()
{
	int test, format; 
	cout<<"\nNo. of elements in power set: "<<pow(2,size);
	cout<<"\nPower Set:  { ";
	for(int i=0;i<pow(2,size);i++)
	{	test =i;		//setting test value equal to i	
	if(test==0)
		{
			cout<<" { } ";
			continue;
		}
		cout<<", { ";			//in the beginning of every element of powerset
		format = 0;
		for(int j=0;j<size;j++)
		{	
			if(test&1)
				{	if(format<size&&format>0)
					{
						cout<<" , ";
					}
					cout<<arr[j];			//element of the element of the powerset
					format++;
				}
			test = test>>1;		
			if(j==size-1)
		{
			cout<<" }  ";
		
			
			}
		}
	
	}
	cout<<"} ";	
}

};

int main()
{
	int ch, element;
	
	do{
		system("cls");
		Set set;
		set.setsize();
		set.enter();
		cout<<"\nThe Set is: ";
		set.show();
		prevset:
		cout<<"\nChoose from the following options: ";
		cout<<"\n1.Cardinality of the set. ";
		cout<<"\n2.Check Element. ";
		cout<<"\n3.Power set. ";
		cin>>ch;
		switch(ch)
		{
			case 1: set.cardinality();
					break;
			case 2: cout<<"\nEnter an element to check for: ";
					cin>>element;
					set.ismember(element);
					break;
			case 3: set.powerset();
					break;
			
			default: cout<<"\nWrong choice entered.";			
		}
		cout<<"\nTo continue with the same set , press 1";
	cout<<"\nTo repeat with a new set, press 2: ";
	cin>>ch;
	if(ch==1)
	{	system("cls");
		set.show();
		goto prevset;
	}
	}while(ch==2);
	return 0;
}
