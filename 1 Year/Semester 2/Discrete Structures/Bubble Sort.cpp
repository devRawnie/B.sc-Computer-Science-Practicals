/*
	Name: 
	Copyright: 
	Author: rohit sharma,rakesh kumar
	Date: 20/02/18 10:21
	Description: 
*/
#include<iostream>
#include<conio.h>
using namespace std;
class Bubble_sort
{
	int* array;
	int size, comparison,comp;
	public:	
//	int N[100], C[100];
	Bubble_sort(int s)
	{ size=s;
	array =new int[size];
	comparison = 0;
	}
	~Bubble_sort()
	{
		delete[] array;
	}
//	void form()
//	{
//		int j;
//		for(int i =size,j=0;i>0;i--,j++)
//			array[j] = i;
//	}
	void enter()
	{
		cout<<"Enter the elements of the array.\n";
		for(int i=0;i<size;i++)
		{
			cout<<"->";
			cin>>array[i];
		}
//	form();
	sort();
	}
void sort()
{
	int temp,pass=0;
	for(int i=0;i<size-1;i++)
	{
	comp=0;
	for(int j = 0;j<size-i-1;j++)
		{	comparison++;
			
			if(array[j]>array[j+1])
			{	comp++;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;	
		
			}
	
		if(comp==0)
		{
			break;
		}
		else{
			cout<<"\nPASS "<<++pass<<": ";
				display();
	
		}
		
	}
}
}
void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<array[i]<<" ";
		}
	}
	
	int getcomp()
	{
		return comparison;
	}
//void printCompute()
//{
//	cout<<"\nN\tComparisons";
//	for(int i=1;i<=100;i++)
//		{
//			cout<<endl;
//			//cout<<N[i];
//			cout<<"\t"<<C[i];
//			
//		}
//	
//}
};
int main()
{
	int s,i=1;
//	do{
//	s = 20*i ;
	cout<<"ENTER THE SIZE OF ARRAY\n->";
	cin>>s;
	Bubble_sort bs(s);
	bs.enter();
	cout<<"\nSORTED ARRAY IS: ";
	bs.display();
	cout<<endl<<"Total no of comparisons: "<<bs.getcomp();
//	bs.N[i] = s;
//	bs.C[i] = bs.getcomp();
//	cout<<endl<<bs.C[i];
//	i++;
//	if(i>99)
//		bs.printCompute();
//	}while(i<=100);

	getch();
	return 0;
}
