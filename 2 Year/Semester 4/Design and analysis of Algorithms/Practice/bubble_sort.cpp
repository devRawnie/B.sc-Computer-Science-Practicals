#include<iostream>
#include<stdio.h>
using namespace std;
int comparisons;
int passes;
void bubble_sort(int arr[], int size){
	//for optimized implentation. This will ensure that atleast one swap takes place during one iteration. If it doesnt, it means the list is already sorted
	bool swapped;
	for(int i = 0 ; i < size - 1 ;i++){
		swapped = false;
		for(int j = 0 ; j < size-i-1; j++ )
		{
			++comparisons;
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		++passes;
		if(!swapped)
			break;
	}
}
void display(int arr[], int size){
	cout<<"Sorted array: ";
	for(int i = 0 ; i < size ;i++)
		cout<<arr[i]<<" ";
	
	printf("\nSize of array: %d\nNo of passes: %d\nNo of comparisons: %d", size, passes, comparisons);
}
int main(){
	int size;
	cout<<"Enter the size of array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of array:\n";
	for(int i = 0 ; i < size; i++)
		cin>>arr[i];
	bubble_sort(arr, size);
	display(arr, size);
	return 0;
}

