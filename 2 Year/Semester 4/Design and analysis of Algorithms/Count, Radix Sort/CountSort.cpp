#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class CountSort{
	int *arr;
	int n;
	int mx = INT_MIN;
	public:
		CountSort(int size)
		{
			n = size;
			arr = new int[n];
		}
		~CountSort()
		{
			delete[] arr;
		}
		void countSort(){
			int *temp,  count[this->n];
			temp=new int[n];
			for(int i=0;i<10;i++)
				count[i]=0;
			for(int i = 0 ; i < n ; i++)
				count[(arr[i]/m)%10]++; 
			for(int i = 1; i < 10; i++)
				count[i] += count[i-1];
		
			
			for(int i =n-1; i >=0 ; i--){
				
				temp[count[(arr[i]/m)%10]-1]=arr[i];
				
				count[(arr[i]/m)%10]--;  
			}
			
			arr=temp;
		}
	void _init_sort(){
		int temp;
		cout<<"\nEnter the elements of array: ";
		for(int i = 0; i < n ; i++){
			cin>>temp;
			arr[i] = temp;
			mx = mx > temp ? mx : temp;
		}
		cout<<endl<<mx;

	}
	
	void displayArray()
		{
			for(int i = 0 ; i < n; i++)
				cout<<arr[i]<<" ";
		}
		
};

int main()
{
	int n;
	cout<<"Enter the number of elements in the array: ";
	cin>>n;
	CountSort cs(n);
	cs._init_sort();
	cs.displayArray();
	return 0;
}
