/*
	Name: 
	Copyright: 
	Author: rohit sharma, rakesh kumar
	Date: 27/02/18 09:24
	Description: 
*/
#include<iostream>
#include<conio.h>
using namespace std;
class Insertion_sort
{
	int* array;
	int size;
	int comparison;
	public:Insertion_sort(int s)
	{ size=s;
	array =new int[size];
	comparison = 0;
	}
	~Insertion_sort()
	{
		delete[] array;
	}
	void enter()
	{
		cout<<"Enter the elements of the array.\n";
		for(int i=0;i<size;i++)
		{
			cout<<"->";
			cin>>array[i];
		}

	}
void sort()
{
	int key,j,i,pass=0;
	for(i=1;i<size;i++)
	{
	
		key = array[i];
		j = i-1;
	
		while(j>=0 && array[j]>key)
		{
			comparison++;
			array[j+1] = array[j];
			j = j-1;
		}
		
            array[j+1] = key;
	  	
		//cout<<"\nPASS "<<++pass<<": \n";
		display();
		//cout<<"COMPARISONS: "<<comparison<<endl;
      
	}
}
int getC()
{
	return comparison;
}
void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<array[i]<<" ";
		}
	
	}
};
int main()
{
	int s;
	cout<<"ENTER THE SIZE OF ARRAY\n->";
	cin>>s;
	Insertion_sort isort(s);
	isort.enter();
	isort.sort();
	cout<<"SORTED ARRAY IS: ";
	isort.display();
	cout<<isort.getC();
	getch();
	return 0;
	
	
}
