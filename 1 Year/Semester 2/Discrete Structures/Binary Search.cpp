/*
	Name: p7
	Copyright: 
	Author: Rohit Sharma, Rakesh Kumar
	Date: 13/02/18 09:39
	Description: In the recursive function {beg<=mid, and end>=mid } are valid
*/
#include<iostream>
#include<process.h>
using namespace std;
class BinarySearch
{
	int beg, end,element;
	int* array;
	int size;
	public: 
	BinarySearch(int s)
	{
           if(s==0){
           cout<<"The size of the array can not be zero\n";
            exit(0);}
        else 
   		{size = s;
		array = new int[size];
            }
	}
	~BinarySearch()
	{
		delete array;
	}
	void enter()
	{
		cout<<"Enter the elements of the array.\n";
		for(int i=0;i<size;i++)
		{
			cout<<"->";
			cin>>array[i];
		}
		sort();
	}
	void sort()
	{
		int temp;
		for(int i=0;i<size-1;i++)
		{
			for(int j=i+1;j<size;j++)
			{
			if(array[i]>array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				
			}
		}
		}
	
    }
	void search()
	{
        beg = 0;            //fpr the cases when user chooses to search for an element in the current array
        end = size-1;
		int m,t;
		cout<<"\nEnter the element to search for:\n->";
		cin>>element;
        		m= (beg+end)/2;
//	cout<<"\nbeg="<<beg<<"end="<<end<< "m="<<t<<endl;
		t = binrec(m); 
	//	cout<<"\nbeg="<<beg<<"end="<<end<< "t="<<t<<endl;
		//cout<<"pos == "<<t<<endl;
		if(t==-1)
			cout<<"\nELEMENT NOT FOUND! (does not exist in the entered array) ";
		else
			cout<<"\nFOUND THE ELEMENT!!. At the pos: "<<t+1;
		
	}
	int binrec(int mid)
	{ 	
		if(array[mid]==element)
		{
			return mid;
		}
		if(array[mid]<element)
		{
		//	cout<<"  mid<element.\n";
			beg = mid+1;
			mid = (beg+end)/2;
		
	//	cout<<"\nbeg="<<beg<<"end="<<end<< "mid="<<mid<<endl;
			if(beg>mid||end<mid)
				return -1;
			else
			return binrec(mid);
		}
		if(array[mid]>element)
		{
			//cout<<"  mid>element.\n";
			end = mid-1;
			mid = (beg+end)/2;
	//	cout<<"\nbeg="<<beg<<"end="<<end<< "mid="<<mid<<endl;
			if(beg>mid||end<mid)
				return -1;
			else
			return	binrec(mid);
		}
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
  
int s,ch;
diffarray:
cout<<"Enter size of the array:\n->";
cin>>s;

    BinarySearch bs(s);
    bs.enter();
    bs.display();
    samearray:
    bs.search();
cout<<"\n1. Repeat with same array";
cout<<"\n2. Repeat with different array";
cout<<"\n3. Quit";
cout<<"\nEnter your choice:\n->";
cin>>ch;

switch(ch)
 {
        case 1: goto samearray;
        case 2: system("cls");
                goto diffarray;
        case 3: exit(0);
        
        default: cout<<"Wrong choice";
                         
        }
return 0;	
}

