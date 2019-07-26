#include<iostream>
#include<stdio.h>
using namespace std;

void heapify(int arr[], int size, int root){
	
	int largest = root;
	int left = 2*root + 1;
	int right = 2*root + 2;
	
	if(left < size && arr[left] > arr[largest])
		largest = left;
	
	if(right < size && arr[right] > arr[largest])
		largest = right;
	
	if(largest != root){
		swap(arr[root], arr[largest]);
		heapify(arr, size, largest);
	}
	
}

void heapsort(int arr[], int size){
	for(int i = size/2 - 1 ; i >= 0 ; i--)
		heapify(arr, size , i);
	for(int i = size -1 ; i >= 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
	
}
void display(int arr[], int size){
	cout<<"Sorted array: ";
	for(int i = 0 ; i < size ;i++)
		cout<<arr[i]<<" ";
	
}
int main(){
	int size;
	cout<<"Enter the size of array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of array:\n";
	for(int i = 0 ; i < size; i++)
		cin>>arr[i];

	heapsort(arr, size);
	display(arr, size);
	return 0;
}

