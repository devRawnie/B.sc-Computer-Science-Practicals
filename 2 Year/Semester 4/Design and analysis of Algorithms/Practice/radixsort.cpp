#include<iostream>
#include<stdio.h>
using namespace std;


void countsort(int arr[], int size, int e){
	int count[10];
	int temp[size];
	//initialize count array by 0
	for(int i = 0; i < 10; i++)
		count[i] = 0;
	//count the occurence of each element	
	for(int i = 0; i < size ; i++)
		++count[(arr[i]/e)%10];
	//form the count array such that the ith element has the correct position of element i in actual array
	for(int i = 1 ; i < 10; i++)
		count[i] += count[i-1];
	for(int i = size-1 ; i >= 0; i--){
		temp[count[(arr[i]/e)%10]-1] = arr[i];
		--count[(arr[i]/e)%10];
	}
	for(int i = 0; i < size; i++)
		arr[i] = temp[i];
	
}

void radixsort(int arr[], int size, int max){
	for(int e = 1 ; max/e > 0 ; e = e * 10)
		countsort(arr, size, e);
}
void display(int arr[], int size){
	cout<<"Sorted array: ";
	for(int i = 0 ; i < size ;i++)
		cout<<arr[i]<<" ";
	
}
int main(){
	int size;
	int mx = INT_MIN;
	cout<<"Enter the size of array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of array:\n";
	for(int i = 0 ; i < size; i++){
		cin>>arr[i];
		mx = max(arr[i], mx);
	}

	radixsort(arr, size, mx);
	display(arr, size);
	return 0;
}

