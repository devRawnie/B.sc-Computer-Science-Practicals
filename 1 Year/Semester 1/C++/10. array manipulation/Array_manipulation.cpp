#include<iostream>
using namespace std;
int ar[50],size,i;
void even_array();
void odd_array();
void sum_ave_array();
void max_min_array();
void dup_array();
void reverse_array();
int main()
{
	int ch;
	char choice='y';
	while(choice=='y')
	{
		system("cls");
		reenter:
		cout<<"Enter the size of array (max 50)\n";
		cin>>size;
		cout<<"Enter the elements of array\n";
		for(i=0;i<size;i++)
		{
			cin>>ar[i];
		}
		retry:
		cout<<"\nCHOOSE FROM THE MENU\n";
		cout<<"1. Print Even Elements of the array\n";
		cout<<"2.Print Odd Elements of the array\n";
		cout<<"3.Print Sum and average of elements of array\n";
		cout<<"4.Print Maximum and minimum element from array\n";
		cout<<"5.Remove Duplicate elements of array\n";
		cout<<"6.Print the array in reverse order\n";
		cout<<"7.Re-enter the value of array\n";
		cout<<"8.Quit\n";
	cout<<"Enter Your Choice: ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
		case 1:	even_array();
				break;
		case 2: odd_array();
				break;
		case 3: sum_ave_array();
				break;
		case 4: max_min_array();
				break;
		case 5: dup_array();
				break;
		case 6: reverse_array();
				break;
		case 7: goto reenter;
		case 8:	exit(0);
		default: cout<<"Wrong choice, Please enter valid choice\n";
				 goto retry;
	}
	cout<<"Enter y to repeat: ";	
	cin>>choice;
	}
	
	
	
	return 0;
}
void even_array()
{int j;
	cout<<"\nEven elements of the array are: \n";
	for(i=0,j=1;i<size;i++)
	{
		if(ar[i]%2==0)
		{
			cout<<j++<<". "<<ar[i]<<endl;
		}
	}
}
void odd_array()
{int j;
	cout<<"\nOdd elements of the array are: \n";
	for(i=0,j=1;i<size;i++)
	{
		if(ar[i]%2==1)
		{
			cout<<j++<<". "<<ar[i]<<endl;
		}
	}
}void sum_ave_array()
{
	int sum = 0,av;
	for(i=0;i<size;i++)
	{
		sum += ar[i]; 
	}
	av = sum/size;
cout<<"The Sum of the elements of array is: "<<sum<<endl;
cout<<"The Average of the elements of array is: "<<av;

}
void max_min_array()
{
	int temp_max,temp_min;
	temp_max = temp_min = ar[0];
	for(i=1;i<size;i++)
	{
		if(temp_max<ar[i])
		{
			temp_max = ar[i];
		}
		if(temp_min>ar[i])
		{
			temp_min = ar[i];
		}
	}
cout<<"The Largest element of the array is: "<<temp_max;
cout<<"The Smallest element of the array is: "<<temp_min;
}
void dup_array()
{
	int j,k;
	for(i=0;i<size;i++)
	{ int newar[50];
		for(j=i+1;j<size;)
		{
			if(ar[i]==ar[j])
			{
				for(k=j;k<size-1;k++)
				{
					ar[k]= ar[k+1];
					
				}
				size--;
			
			}
			else
			{
				j++;
			}
		}
		
	}
cout<<"The array after removing duplicates is: "<<endl;
for(i=0;i<size;i++)
{
	cout<<i+1<<". "<<ar[i]<<endl;
}


}


void reverse_array()
{
	int j;
	for(i=size-1,j=1;i>=0;i--,j++)
	{
		cout<<j<<". "<<ar[i]<<endl;
	}
}

