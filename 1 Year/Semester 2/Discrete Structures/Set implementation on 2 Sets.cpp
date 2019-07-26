/*
  Name:P2, set operations
  Copyright: none
  Author: rakesh kumar, rohit sharma
  Date: 16/01/18 10:11
  Description: implement set operations on two sets.
*/

#include<iostream>
#include<conio.h>
#include<process.h>
#include<math.h>
using namespace std;
class Set{

	public:
		int *arr, size;
	Set()
	{
		size = 0;
		arr = NULL;
	}
	Set(Set& temp_ob)
	{
		size = temp_ob.size;
		arr = temp_ob.arr;
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
		cout<<"  { ";
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
Set setunion(Set& ob)
{
Set temp;
temp.size = size + ob.size;
temp.arr = new int[temp.size];
int i, j;
for(i=0;i<size;i++)
{
	temp.arr[i] = arr[i];
	}	
for(j=0,i=size;j<ob.size;j++,i++)
	{
		temp.arr[i] = ob.arr[j];
	}
temp.unique();
return temp;}

Set setintersection(Set& ob)
{
	Set temp;
	temp.size = ((size>=ob.size)?ob.size:size);
	
	temp.arr = new int[temp.size];
	int i,j,k=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<ob.size;j++)
		{
			if(arr[i]==ob.arr[j])
			{
				temp.arr[k++]= arr[i];
				
				break;
			}
		}
	}
temp.size = k;
return temp;
}
Set setdifference(Set& ob)
{
	Set temp;
	temp.size = ((size>=ob.size)?ob.size:size);
	temp.arr = new int[temp.size];
	int i, j,k=0;
	
	for( i = 0;i<size;i++)
	{
		for( j = 0;j<ob.size;j++)
		{
			if(arr[i]==ob.arr[j])
			{
				break;
			}
		}
	if(j==ob.size)
	{
		temp.arr[k++]=arr[i];
	}
	
	}
	temp.size = k;
	return temp;
	

}

bool subset(Set& ob)
{
	int i, j;
	if(size<=ob.size)
	{
	
	for( i = 0;i<size;i++)
	{
		for( j = 0;j<ob.size;j++)
		{
			if(arr[i]==ob.arr[j])
			{
				break;
			}
		}
	if(j==ob.size)
	{
		return false;
	}
	
	}
	return true;
	
}
else{
	return false;
}

}
Set symdiff(Set& ob)
{
	Set temp1, temp2, temp3;
	temp1 = setunion(ob);
	temp2 = setintersection(ob);
	temp3 = temp1.setdifference(temp2);
	return temp3;
}
Set complement(Set& ob)
{
	int i=0,big;
	Set temp1,temp2;
	Set temp3 = ob;
	cout<<"Original Set: ";
	ob.show();
	big = ob.arr[i];
	for(i=1;i<ob.size;i++)
{
	if(ob.arr[i]>big)
	{
		big = ob.arr[i];
	}
}
 temp1.size=big*2;
temp1.arr = new int[temp1.size];
 for(i=0;i<temp1.size;i++)
 {
 	temp1.arr[i] = i+1;
 }
 cout<<"\nUniversal set is: \n";
 temp1.show();
temp2.size = temp1.size - ob.size;
temp2.arr = new int[temp2.size];
temp2 = temp1.setdifference(temp3);
return temp2;
}
void product(Set& ob)
{
  int i,j;
  cout<<"Cartesian product of the set is: \n{ ";
  for(i=0;i<size;i++)
  {
  	
  	for(j=0;j<ob.size;j++)
	  {
	 	cout<<"( "<<arr[i]<<", "<<ob.arr[j]<<" )"; 	
		if(i==(size-1)&&(j==(ob.size-1)))
		{
			break;
		}
		cout<<", ";
}
	  }
	  cout<<" }";	
}
};
int main()
{
		int ch;
	do{
	

	Set A, B, C;
	A.setsize();
	A.enter();
	B.setsize();
	B.enter();
	system("cls");
	cout<<"\nSet 1: ";
	A.show();
	cout<<"\nSet 2: ";
	B.show();
	prevset:
		cout<<"\nChoose from the following options: ";
		cout<<"\n1.Union of two sets. ";
		cout<<"\n2.Intersection of two sets. ";
		cout<<"\n3.Set Difference of two sets. ";
		cout<<"\n4.Check subset ";
        cout<<"\n5.Set Complement. ";
		cout<<"\n6.Cartesian Product ";
		cout<<"\n7.Symmetric Difference ";
	cin>>ch;
	switch(ch)
	{
		case 1: C = A.setunion(B);
				C.show();
				break;
		case 2: C = A.setintersection(B);
				C.show();
				break;
		case 3: cout<<"Press 1 for A-B \tPress 2 for B-A\n";
				cin>>ch;
				if(ch==1)
				{
					C=A.setdifference(B);
					C.show();
				}
				else
					{
					C = B.setdifference(A);
					C.show();
			}
				break;	
		case 4: cout<<"Press 1 to check for AcB\tPress 2 to check for BcA\n";
				cin>>ch;
				if(ch==1)
				{ if(A.subset(B))
				{
					cout<<"YES, AcB is true";
				}
				else{
						cout<<"NO, AcB is false";
				}
                    }
                else{
                if(B.subset(A))
                    {
                	cout<<"YES, BcA is true";  	
					}
				else{
						cout<<"NO, BcA is false";
				}
					}
				break;
		case 5: cout<<"Press 1 to find A'\tPress 2 to find B'\n";
				cin>>ch;
				if(ch==1)
				{ C = A.complement(A);
                    cout<<"\nSet Complement: ";
                   C.show();
					}
                else{
                C = B.complement(B);
                cout<<"\nSet Complement: ";
                C.show();
				}
				break;
		case 6: cout<<"Press 1 to find A*B'\tPress 2 to find B*A'\n";
				cin>>ch;
				if(ch==1)
				{
                    A.product(B);
                    }
                    else{
                     B.product(A);
                      }
				break;
		case 7: cout<<"Press 1 to find A symm B\tPress 2 to find B symm A\n";
				cin>>ch;
				if(ch==1)
                {   C = A.symdiff(B);
                    C.show();
					}
                else{
                    C = B.symdiff(A);
                    C.show();
					}
                    break;
		
        default: cout<<"Wrong choice";
	}
cout<<"\nPress 1 to repeat with same sets\nPress 2 to coninue with new sets\nPress 3 to exit";
cin>>ch;
if(ch==1)
{
	system("cls");
	cout<<"\nSet 1: ";
	A.show();
	cout<<"\nSet 2: ";
	B.show();
	goto prevset;
}
if(ch==3)
{
	exit(0);
}
}while(ch==2);
	return 0;
}
